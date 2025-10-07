#pragma once
#include "interfaces.hpp"
#include "raylib.h"

namespace FrogToad {
    class RaylibView : public IView {
    public:
        void draw(const BoardModel& m) override;

        int windowW() const;
        int windowH() const;
    };
}
