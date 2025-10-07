#include "board_model.hpp"

namespace FrogToad {
    // --- Public API ---

    void BoardModel::reset() {
        board = StartingBoard;
        isGameSolved = false;
    }

    bool BoardModel::isSolved() const { 
        return isGameSolved; 
    }

    BoardModel::Cell BoardModel::cellAt(int i) const {
        return isIndexValid(i) ? board[i] : Cell::Empty;
    }

    char BoardModel::toChar(Cell c) {
        switch (c) {
            case Cell::Empty: return '.';
            case Cell::Frog: return 'F';
            case Cell::Toad: return 'T';
            default: return 'X'; // Invalid! There are only three states to the enum.
        }
    }

    bool BoardModel::tryMove(int i) {
        if (!isIndexValid(i) || isCellEmpty(i)) return false;

        Cell c{ board[i] };
        int slideMove{ i + moveDirection(c) };
        int jumpMove{ i + 2 * moveDirection(c) };

        if (isIndexValid(slideMove) && !isCellEmpty(slideMove) && isIndexValid(jumpMove) && isCellEmpty(jumpMove)) {
            board[jumpMove] = c;
        }
        else if (isIndexValid(slideMove) && isCellEmpty(slideMove)) {
            board[slideMove] = c;
        }
        else {
            return false;
        }

        board[i] = Cell::Empty;
        evaluateBoard();
        return true;
    }

    // --- Private Static Constexpr Helpers ---

    constexpr bool BoardModel::isIndexValid(int i) { 
        return i >= 0 && i < BoardSize; 
    }
    
    constexpr int BoardModel::moveDirection(Cell c) { 
        return (c == Cell::Frog) ? +1 : -1; 
    }

    // --- Private Instance Helpers ---

    bool BoardModel::isCellEmpty(int i) const { 
        return board[i] == Cell::Empty;
    }

    void BoardModel::evaluateBoard() {
        isGameSolved = (board == GoalBoard);
    }

} // namespace FrogToad
