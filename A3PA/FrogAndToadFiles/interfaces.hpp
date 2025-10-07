#pragma once
#include "board_model.hpp"

namespace FrogToad {
    /**
     * @brief Abstract view interface for rendering our game.
     *
     * Views must implement a single draw operation that receives a read-only
     * snapshot of the current board state to render.
     */
    class IView {
    public:
        virtual ~IView() = default;

        /**
         * @brief Render the provided board state.
         *
         * Accepts a const reference to the current @c BoardModel. The
         * parameter is intentionally unnamed; implementers should fetch all
         * data needed to draw without mutating the model.
         */
        virtual void draw(const BoardModel&) = 0;
    };

    /**
     * @brief Abstract controller interface plus a model helper.
     *
     * Controllers encapsulate player or AI input and advance the model by
     * issuing moves. 
     */
    class IController {
    public:
        virtual ~IController() = default;

        /**
         * @brief Advance the game by producing the next move.
         *
         * Implementations should read input (human or AI) and apply it to the
         * model—usually by delegating to applyCommand.
         */
        virtual void nextMove(BoardModel&) = 0;

        /**
         * @brief Translate an ASCII character into a model command.
         *
         * @param m Reference to the model.
         * @param key Input character representing a command (e.g., '1'..'9', 'r'/'R').
         * @return True if the command was recognized and applied; otherwise false.
         *
         * @details
         * - 'r' or 'R' resets the model via BoardModel::reset().
         * - Digit characters are mapped to zero-based indices by subtracting the
         *   character '1' from the pressed key (e.g., '1'→0, '2'→1, '3'→2),
         *   and passed to BoardModel::tryMove().
         *
         * @note The digit-to-index conversion relies on ASCII ordering:
         *       '1' - '1' = 0, '2' - '1' = 1, '3' - '1' = 2, etc.
         */
        static bool applyCommand(BoardModel& m, char key) {
            if (key == 'r' || key == 'R') { m.reset(); return true; }
            return m.tryMove(key - '1');
        }
    };
}
