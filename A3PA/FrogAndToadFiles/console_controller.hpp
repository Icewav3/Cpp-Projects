#pragma once
#include "interfaces.hpp"

namespace FrogToad {
	class ConsoleController : public IController {
	public:
		bool nextMove(BoardModel &m) override; 
	};
}
