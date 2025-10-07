#pragma once
#include <array>

namespace FrogToad {
    /**
     * @brief Game model holding board state, move logic, and solution evaluation.
     */
    class BoardModel {
    public:
        static constexpr int BoardSize = 7;

        enum class Cell { Empty, Frog, Toad }; // Empty, Frog moves right, Toad moves left

        // --- Public API ---

        /** @brief Reset to the starting configuration. */
        void reset();

        /** @brief Has the game been solved?  */
        bool isSolved() const;

        /**
         * @brief Cell at index i.
         * @param i Zero-based index into the board.
         * @return Cell value; returns Cell::Empty if i is out of range.
         */
        Cell cellAt(int i) const;

        /**
         * @brief Convert a cell to a character representation.
         * @param c Cell value.
         * @return '.' for Empty, 'F' for Frog, 'T' for Toad.
         */
        static char toChar(Cell c);

        /**
         * @brief Attempt to move the piece at index i.
         *
         * Applies a slide or jump is a space is available (direction depends
         * on the piece type). Updates internal state on success.
         *
         * @param i Zero-based index of the piece to move.
         * @return True if a move was applied; otherwise false.
         */
        bool tryMove(int i);

    private:
        /** @brief Initial board layout. */
        static constexpr std::array<Cell, BoardSize> StartingBoard{ Cell::Frog, Cell::Frog, Cell::Frog, Cell::Empty, Cell::Toad, Cell::Toad, Cell::Toad };
        
        /** @brief Goal board layout. */
        static constexpr std::array<Cell, BoardSize> GoalBoard{ Cell::Toad, Cell::Toad, Cell::Toad, Cell::Empty, Cell::Frog, Cell::Frog, Cell::Frog };

        // Object State
        
        /** @brief Cached game-solved flag. */
        bool isGameSolved{ false };

        /** @brief The actual game board. */
        std::array<Cell, BoardSize> board{ StartingBoard };

        // Static Constexpr Helpers
        /**
         * @brief Bounds check for board indices.
         * @param i Index to test.
         * @return @c true if @p k is within [0, BoardSize).
         */
        static constexpr bool isIndexValid(int i);

        /**
         * @brief Direction of motion for a piece.
         * @param c Cell value.
         * @return +1 (right) for Frog, -1 (left) for Toad.
         */
        static constexpr int moveDirection(Cell c);

        // Instance Helpers

        /**
         * @brief Test if a cell is empty.
         * @param i Index to test (assumed valid).
         * @return True if the cell is Cell::Empty, else false.
         */
        bool isCellEmpty(int k) const;

        /** @brief Recompute isGameSolved based on the current board. */
        void evaluateBoard(); 
    };
}
