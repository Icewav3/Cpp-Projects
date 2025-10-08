#include "raylib_controller.hpp"
#include "raylib.h"

namespace FrogToad {
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
