#include "console_controller.hpp"
#include <conio.h>

namespace FrogToad{
	void ConsoleController::nextMove(BoardModel& m) {
		int ch{ _getch() };
		applyCommand(m, ch);
	}
}