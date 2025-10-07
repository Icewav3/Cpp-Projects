#pragma once
#include "interfaces.hpp"

namespace FrogToad {
    /**
     * @brief Plain-text console implementation of FrogToad::IView.
     */
    class ConsoleView : public IView {
    public:
        /**
         * @brief Render the current board to stdout.
         * @param m Immutable board model to display.
         */
        void draw(const BoardModel& m) override;
    };
}
