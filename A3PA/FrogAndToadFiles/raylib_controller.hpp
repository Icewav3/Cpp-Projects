#pragma once
#include "interfaces.hpp"

namespace FrogToad {
    class RaylibController : public IController {
    public:
        void nextMove(BoardModel& m) override;
    };
}
