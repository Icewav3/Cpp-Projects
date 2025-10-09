#include <array>
#include <string>
#include "FrogAndToadFiles/board_model.hpp"

#define RAYLIB_BUILD

#ifdef RAYLIB_BUILD
#include "raylib.h"
#include "FrogAndToadFiles/raylib_controller.hpp"
#include "FrogAndToadFiles/raylib_view.hpp"
#else
#include <iostream>
#include "FrogAndToadFiles/console_controller.hpp"
#include "FrogAndToadFiles/console_view.hpp"
#include "FrogAndToadFiles/ansi_view.hpp"
#endif

#ifndef RAYLIB_BUILD
int main() {
	FrogToad::BoardModel model;
	FrogToad::AnsiView view;
	FrogToad::ConsoleController controller;

	std::cout << "Toads & Frogs - Console\n\n";

	while (true) {
		view.draw(model);
		controller.nextMove(model);
		std::cout << "\n";
	}

	return 0;
}
#else
int main() {
	FrogToad::BoardModel model;
	FrogToad::RaylibView view;
	FrogToad::RaylibController ctrl;

	InitWindow(view.windowW(), view.windowH(), "Toads & Frogs - Raylib");
	SetTargetFPS(60);
	view.init();
	while (!WindowShouldClose()) {
		if (!ctrl.nextMove(model)) {
			break;
		}

		BeginDrawing();
		view.draw(model);
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
#endif

/* Time
 * P1 = 1hr - medium
 * P2 = 2hr - hard
 * P3 = 1 min - very easy
 * P4 = NULL

 * Reflection:
 * One of the biggest issues I had was during part 2. I was debugging why my images were not being found
 * and it had turned out that it was a conflict of raylib being in one directory and cmake being in another.
 * Another big issue I had ran into was that #ifndef preprocessors don't actually have any static analysis, I had
 * misspelled RAYLIB as RALIB and there were no signs of error. It looked close so I didn't realize until way later.
 * I also had some minor issues initially with setting up the environment as the files were for VS and I am running
 * CLION.
 *
 * Me personally, I am a big fan of codes
 */
