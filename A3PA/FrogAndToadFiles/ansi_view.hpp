#pragma once
#include "interfaces.hpp"
#include <string>

namespace FrogToad {
    /**
     * @brief ANSI terminal implementation of FrogToad::IView.
     *
     * Renders the board using ANSI escape sequences on a text console.
     */
    class AnsiView : public IView {
    public:

	    AnsiView();
	    ~AnsiView();

        /**
        * @brief Draw the current board state to the terminal.
        * @param m Immutable board model to render.
        */
	    void draw(const BoardModel& m) override;

    private:
    
        // ANSI Escape Code Helpers
        static const std::string resetStyles() { return "\x1b[0m"; } 
        static const std::string clearScreen() { return "\x1b[2J"; };
        static const std::string hideCursor()  { return "\x1b[?25l"; }
        static const std::string showCursor()  { return "\x1b[?25h"; }
        static const std::string eraseAfter()  { return "\x1b[0J"; }
        static const std::string cursorHome()  { return "\x1b[H";  }
        static const std::string white()       { return "\x1b[1m"; }
        static const std::string grey()        { return "\x1b[37m"; }
        static const std::string red()         { return "\x1b[38;5;196m"; }
        static const std::string blue()        { return "\x1b[38;5;33m"; }
        static const std::string green()       { return "\x1b[38;5;34m"; }
        static const std::string bell()        { return "\a"; }
    };
}

