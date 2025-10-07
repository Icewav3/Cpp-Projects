#include "raylib_view.hpp"

namespace FrogToad {
	void RaylibView::draw(const BoardModel& m) {
		ClearBackground(RAYWHITE);
	}

	int RaylibView::windowW() const { return 600; }
	int RaylibView::windowH() const { return 300; }
}