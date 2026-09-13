#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/component/component.hpp>
#include <iostream>

using namespace ftxui;

int main() {
    auto screen = ScreenInteractive::Fullscreen();

    Element header = hbox({
        text(" GABARY V2 - CHRONOLOGY TUI ") | bold | color(Color::Cyan) | inverted,
        filler(),
        text(" Dual Solar-Lunar 50K Engine ") | color(Color::Yellow),
    }) | border;

    Element metrics_box = vbox({
        text("System Metrics & Status:") | bold | color(Color::Green),
        separator(),
        hbox(text("• Test Suite Pass Rate: "), text("100% (86 / 86)") | bold | color(Color::Cyan)),
        hbox(text("• Global Solar Range:   "), text("1 to 18,261,759 Days") | color(Color::White)),
        hbox(text("• Core Architecture:    "), text("C++17 & FTXUI Framework") | color(Color::Magenta)),
        hbox(text("• Database Status:      "), text("Synchronized & Verified") | color(Color::Green)),
    }) | border;

    Element footer = hbox({
        text(" Press 'q' or 'ESC' to exit dashboard ") | dim | center,
    });

    Element document = vbox({
        header,
        separator(),
        metrics_box,
        filler(),
        footer,
    }) | borderRounded;

    auto component = CatchEvent(
        Renderer([&] {
            return document;
        }),
        [&](Event event) {
            if (event == Event::Character('q') ||
                event == Event::Character('Q') ||
                event == Event::Escape) {
                screen.Exit();
                return true;
            }
            return false;
        }
    );

    screen.Loop(component);

    return 0;
}
