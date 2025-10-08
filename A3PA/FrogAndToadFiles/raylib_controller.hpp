#pragma once
#include "interfaces.hpp"

namespace FrogToad {
    class RaylibController : public IController {
    public:
	    bool nextMove(BoardModel &m) override;
    };
}
