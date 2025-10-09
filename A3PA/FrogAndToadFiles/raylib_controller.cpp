#include "raylib_controller.hpp"
#include "raylib.h"


namespace FrogToad {
	/**
	 * @brief Handles the next move in a game.
	 *
	 * This method checks for user input and updates the board model accordingly.
	 * If 'Q' is pressed, it returns false to indicate that the game loop should stop.
	 * If 'R' is pressed, it resets the board.
	 * Otherwise, it attempts to make a move based on the number keys pressed (1-7).
	 *
	 * @param m Reference to the BoardModel that represents the current state of the game board.
	 * @return true if a valid move was made or no action was necessary, false otherwise.
	 */
	bool RaylibController::nextMove(BoardModel &m) {
		if (IsKeyPressed(KEY_Q)) {
			return false;
		}
		if (IsKeyPressed(KEY_R)) {
			m.reset();
		} else {
			int move = -1;
			if (IsKeyPressed(49)) {
				move = 0;
			} else if (IsKeyPressed(50)) {
				move = 1;
			} else if (IsKeyPressed(51)) {
				move = 2;
			} else if (IsKeyPressed(52)) {
				move = 3;
			} else if (IsKeyPressed(53)) {
				move = 4;
			} else if (IsKeyPressed(54)) {
				move = 5;
			} else if (IsKeyPressed(55)) {
				move = 6;
			}
			if (move != -1) {
				m.tryMove(move);
			}
		}
		return true;
	}
}
