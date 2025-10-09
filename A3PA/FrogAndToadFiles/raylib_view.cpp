#include "raylib_view.hpp"
#include <string>

namespace FrogToad {
	/**
	 * @brief Initializes the view, loading textures for game elements.
	 *
	 * This method loads the textures for the frog and toad from the specified paths.
	 */
	void RaylibView::init() {
		frogTexture = LoadTexture("Art/Frog.png");
		toadTexture = LoadTexture("Art/Toad.png");
	}

	/**
	 * Draw the game board and pieces.
	 *
	 * @param m Reference to the current board model. @param
	 * */
	void RaylibView::draw(const BoardModel &m) {
		ClearBackground(RAYWHITE);
		const int leftPadding = 40;
		const int topPadding = 120;
		// Title
		DrawText("Toads & Frogs", leftPadding, 30, 30, BLACK);
		DrawText("1 to 7 = move index;  R = restart, Q = close", leftPadding, 80, 20, BLACK);
		// Draw board
		const int rectSize = 90;
		for (int i = 0; i < m.BoardSize; i++) {
			DrawRectangleLines(leftPadding + (i * rectSize), topPadding, rectSize, rectSize, BLACK);
		}
		//Draw numbers
		for (int i = 0; i < m.BoardSize; i++) {
			DrawText(TextFormat("%d", i + 1), leftPadding + (i * rectSize) + rectSize / 2, topPadding + rectSize, 20,
			         BLACK);
		}
		//Draw forgs
		for (int i = 0; i < m.BoardSize; i++) {
			BoardModel::Cell cell = m.cellAt(i);
			if (cell == BoardModel::Cell::Empty) continue;
			int CellX = leftPadding + (i * rectSize); // center of cell
			int CellY = topPadding;
			Vector2 Cell = Vector2(CellX, CellY);
			float scale = 90.0f / 315.0f;
			Texture2D texture = (cell == BoardModel::Cell::Frog) ? frogTexture : toadTexture;
			DrawTextureEx(texture, Cell, 0, scale, WHITE);
		}

		if (m.isSolved()) {
			DrawText("Congratulations, you solved it!", leftPadding, topPadding + rectSize + 40, 20, BLACK);
		}
	}

	/**
	 * @brief Get the width of the window.
	 *
	 * This function returns the current width of the window used for rendering.
	 *
	 * @return int The width of the window in pixels.
	 */
	int RaylibView::windowW() const { return 800; }
	/**
	 * @brief Get the height of the window.
	 *
	 * @return The height of the window in pixels.
	 */
	int RaylibView::windowH() const { return 300; }
}
