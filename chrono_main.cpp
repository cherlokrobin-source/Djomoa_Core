#include <notcurses/notcurses.h>
#include <cmath>
#include <ctime>
#include <unistd.h>
#include <sys/ioctl.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <algorithm>

#if __has_include("include/chronology_engine.hpp")
    #include "include/chronology_engine.hpp"
#elif __has_include("include/gabary.hpp")
    #include "include/gabary.hpp"
#endif

void draw_panel_box(struct ncplane* plane, int y, int x, int h, int w, uint32_t rgb, const std::string& title) {
    if (h < 3 || w < 8) return;
    
    ncplane_set_fg_rgb8(plane, (rgb >> 16) & 0xFF, (rgb >> 8) & 0xFF, rgb & 0xFF);
    ncplane_putstr_yx(plane, y, x, "┌");
    ncplane_putstr_yx(plane, y, x + w - 1, "┐");
    ncplane_putstr_yx(plane, y + h - 1, x, "└");
    ncplane_putstr_yx(plane, y + h - 1, x + w - 1, "┘");

    for (int i = 1; i < w - 1; ++i) {
        ncplane_putstr_yx(plane, y, x + i, "─");
        ncplane_putstr_yx(plane, y + h - 1, x + i, "─");
    }
    for (int j = 1; j < h - 1; ++j) {
        ncplane_putstr_yx(plane, y + j, x, "│");
        ncplane_putstr_yx(plane, y + j, x + w - 1, "│");
    }

    if (!title.empty() && w > static_cast<int>(title.length() + 6)) {
        ncplane_set_fg_rgb8(plane, 255, 255, 255);
        std::string formatted_title = "┤ " + title + " ├";
        ncplane_putstr_yx(plane, y, x + 2, formatted_title.c_str());
    }
}

void render_polar_scope(struct ncplane* plane, int y, int x, int h, int w, double diurnal, double annual, double epoch, double horizon, double lunar_cycle) {
    draw_panel_box(plane, y, x, h, w, 0xF1FA8C, "POLAR CHRONO SCOPE");
    if (h < 4) return;

    int cy = y + (h / 2);
    int cx = x + (w / 2);
    
    ncplane_set_fg_rgb8(plane, 98, 114, 164);
    ncplane_putstr_yx(plane, cy, cx - 4, "─ ┼ ─");
    ncplane_putstr_yx(plane, cy - 1, cx, "│");
    ncplane_putstr_yx(plane, cy + 1, cx, "│");

    auto plot_node = [&](double ratio, uint32_t rgb, const std::string& sym) {
        double rad = ratio * 2.0 * M_PI - (M_PI / 2.0);
        int px = cx + static_cast<int>(2.0 * cos(rad) * 2.0);
        int py = cy + static_cast<int>(1.0 * sin(rad));
        if (py > y && py < y + h - 1 && px > x && px < x + w - 1) {
            ncplane_set_fg_rgb8(plane, (rgb >> 16) & 0xFF, (rgb >> 8) & 0xFF, rgb & 0xFF);
            ncplane_putstr_yx(plane, py, px, sym.c_str());
        }
    };

    plot_node(diurnal,     0x50FA7B, "A");
    plot_node(annual,      0xF1FA8C, "S");
    plot_node(epoch,       0xFFB86C, "M");
    plot_node(horizon,     0xBD93F9, "H");
    plot_node(lunar_cycle, 0x8BE9FD, "☾");
}

void render_metrics_panel(struct ncplane* plane, int y, int x, int h, int w, double diurnal, double annual, double epoch, double horizon, double lunar_cycle, double grand_cyc, double micro_hrm) {
    draw_panel_box(plane, y, x, h, w, 0x50FA7B, "REAL-TIME CYCLIC & LUNAR TABLES");
    if (h < 4) return;

    ncplane_set_fg_rgb8(plane, 139, 233, 253);
    if (h >= 5 && w > 50) {
        ncplane_putstr_yx(plane, y + 1, x + 2, "VECTOR ENGINE   DEGREE   RATIO    PHASE PROGRESS");
    }

    auto print_row = [&](int line, uint32_t color, const std::string& label, double ratio) {
        if (y + line >= y + h - 1) return;
        std::stringstream ss;
        ss << std::left << std::setw(14) << label
           << std::right << std::setw(6) << std::fixed << std::setprecision(1) << (ratio * 360.0) << "° "
           << std::right << std::setw(6) << std::setprecision(4) << ratio << "  ";
        
        ncplane_set_fg_rgb8(plane, (color >> 16) & 0xFF, (color >> 8) & 0xFF, color & 0xFF);
        ncplane_putstr_yx(plane, y + line, x + 2, ss.str().c_str());

        int rem_w = w - ss.str().length() - 4;
        if (rem_w > 6) {
            std::string bar = "[";
            int filled = static_cast<int>(ratio * (rem_w - 2));
            for (int b = 0; b < rem_w - 2; ++b) {
                bar += (b < filled) ? "█" : "░";
            }
            bar += "]";
            ncplane_putstr_yx(plane, y + line, x + 2 + ss.str().length(), bar.c_str());
        }
    };

    print_row(2, 0x50FA7B, "DIURNAL [A]", diurnal);
    print_row(3, 0xF1FA8C, "ANNUAL  [S]", annual);
    print_row(4, 0xFFB86C, "EPOCH   [M]", epoch);
    print_row(5, 0xBD93F9, "HORIZON [H]", horizon);
    print_row(6, 0x8BE9FD, "LUNAR-D [☾]", lunar_cycle); // الجدول القمري الجديد المعتمد على الرقم 17250176
    print_row(7, 0x50C878, "GRAND-CYC [G]", grand_cyc);
    print_row(8, 0xFF79C6, "MICRO-HRM [μ]", micro_hrm);
}

void render_wave_panel(struct ncplane* plane, int y, int x, int h, int w, double diurnal, double lunar_cycle) {
    draw_panel_box(plane, y, x, h, w, 0xFF79C6, "TEMPORAL RESONANCE WAVE");
    if (h < 3) return;

    int max_pts = w - 4;
    double amplitude = (h - 2) / 2.0;
    double mid_y = y + 1 + amplitude;

    ncplane_set_fg_rgb8(plane, 80, 250, 150);

    for (int i = 0; i < max_pts; ++i) {
        double norm_i = static_cast<double>(i) / max_pts;
        double wave_val = std::sin((norm_i + diurnal) * 2.0 * M_PI) * std::cos((norm_i + lunar_cycle) * M_PI);
        int wy = static_cast<int>(mid_y - (wave_val * amplitude));
        wy = std::clamp(wy, y + 1, y + h - 2);

        ncplane_putstr_yx(plane, wy, x + 2 + i, "■");
    }
}

int main() {
    struct notcurses_options opts = {};
    struct notcurses* nc = notcurses_init(&opts, NULL);
    if (!nc) return 1;
    struct ncplane* stdplane = notcurses_stdplane(nc);

    long long abs_day = 18894389; 
    long long lunar_base_offset = 17250176;

    while (true) {
        ncplane_erase(stdplane);

        struct winsize w_size;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w_size);
        unsigned int dimy = w_size.ws_row > 0 ? w_size.ws_row : ncplane_dim_y(stdplane);
        unsigned int dimx = w_size.ws_col > 0 ? w_size.ws_col : ncplane_dim_x(stdplane);

        ncplane_resize_simple(stdplane, dimy, dimx);

        draw_panel_box(stdplane, 0, 0, dimy, dimx, 0x6272A4, "GABARY V2 NATIVE :: LUNAR-CHRONO-ENGINE");

        double diurnal     = std::fmod(static_cast<double>(abs_day), 1.0);
        double annual      = std::fmod(static_cast<double>(abs_day) / 365.2422, 1.0);
        double epoch       = std::fmod(static_cast<double>(abs_day) / 3652.422, 1.0);
        double horizon     = std::fmod(static_cast<double>(abs_day) / 50000.0, 1.0);
        
        // حساب الأيام القمرية بناءً على الرقم الأساسي 17250176 ودورة الشهر الاقتراني (29.53058 يوم)
        double total_lunar_days = static_cast<double>(lunar_base_offset + (abs_day % 1000000));
        double lunar_cycle = std::fmod(total_lunar_days / 29.53058886, 1.0);

        double grand_cyc   = std::fmod(epoch * 1.618, 1.0);
        double micro_hrm   = std::fmod(diurnal * 3.1415, 1.0);

        int avail_h = dimy - 2;
        int scope_h   = std::max(5, static_cast<int>(avail_h * 0.18));
        int metrics_h = std::max(10, static_cast<int>(avail_h * 0.45)); // مساحة تتسع لجدول الأيام القمرية الإضافي
        int wave_h    = avail_h - scope_h - metrics_h;

        if (wave_h < 4) {
            scope_h = 5;
            metrics_h = 10;
            wave_h = avail_h - scope_h - metrics_h;
        }

        render_polar_scope(stdplane, 1, 1, scope_h, dimx - 2, diurnal, annual, epoch, horizon, lunar_cycle);
        render_metrics_panel(stdplane, 1 + scope_h, 1, metrics_h, dimx - 2, diurnal, annual, epoch, horizon, lunar_cycle, grand_cyc, micro_hrm);
        render_wave_panel(stdplane, 1 + scope_h + metrics_h, 1, wave_h, dimx - 2, diurnal, lunar_cycle);

        ncplane_set_fg_rgb8(stdplane, 98, 114, 164);
        std::stringstream status_ss;
        status_ss << "LUNAR-BASE: " << lunar_base_offset << " | ABS_DAY: " << abs_day;
        std::string status = status_ss.str();
        ncplane_putstr_yx(stdplane, dimy - 1, std::max(1, static_cast<int>(dimx - status.length()) / 2), status.c_str());

        notcurses_render(nc);

        abs_day++; // حركة حية مستمرة للأيام

        ncinput ni;
        uint32_t key = notcurses_get_nblock(nc, &ni);
        if (key != 0 && key != (uint32_t)-1) {
            if (ni.evtype == NCTYPE_PRESS) {
                if (key == NCKEY_RIGHT) { abs_day += 10; }
                else if (key == NCKEY_LEFT) { abs_day -= 10; }
                else if (key == 'q' || key == 'Q' || key == NCKEY_ESC) { break; }
            }
        }

        usleep(120000);
    }

    notcurses_stop(nc);
    return 0;
}
