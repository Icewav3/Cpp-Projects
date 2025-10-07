#include "ansi_view.hpp"
#include <iostream>

namespace FrogToad {
	AnsiView::AnsiView() {
		std::cout << clearScreen() << cursorHome() << hideCursor();
	}
	AnsiView::~AnsiView() {
		std::cout << resetStyles() << showCursor();
	}

	void AnsiView::draw(const BoardModel& m) {
		std::cout << cursorHome() << resetStyles();

		std::cout << white() << "Toads & Frogs" << eraseAfter() << "\n";
		std::cout << grey() << "1.." << m.BoardSize << " = Move & R = Restart\n\n" << resetStyles();

		// Display the board row:
		for (int i = 0; i < m.BoardSize; ++i) {
			const auto c = m.cellAt(i);

			if (c == BoardModel::Cell::Frog) {
				std::cout << blue();
			}
			else if (c == BoardModel::Cell::Toad) {
				std::cout << red();
			}
			else {
				std::cout << grey();
			}

			std::cout << BoardModel::toChar(c) << ' ';
		}
		std::cout << '\n';

		// Display the numeric index row: 
		std::cout << grey();
		for (int i = 1; i <= m.BoardSize; ++i) {
			std::cout << i << ' ';
		}
		std::cout << "\n\n";

		// Status line
		if (m.isSolved()) {
			std::cout << bell() << green() << "Solved! R to restart.\n";
		}
		else {
			std::cout << grey() << "Choose a piece to move.\n";
		}

		// If previous frame printed longer lines, clear the rest of the screen area
		std::cout << eraseAfter();
	}
 }
