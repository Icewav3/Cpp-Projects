#pragma once
#include "interfaces.hpp"

namespace FrogToad {
	class ConsoleController : public IController {
	public:
		void nextMove(BoardModel& m) override; 
	};
}
