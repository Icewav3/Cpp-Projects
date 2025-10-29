#include <iostream>

// Add raylib header
#include "raylib.h"
#include "Classes/CanvasManager.h"

int main() {
	// Initialize the window
	const int screenWidth = 1980;
	const int screenHeight = 1080;

	InitWindow(screenWidth, screenHeight, "raylib empty window example");

	SetTargetFPS(60); // Set our game to run at 60 frames-per-second
	CanvasManager canvasManager;
	while (!WindowShouldClose()) {
		float deltaTime = GetFrameTime();
		canvasManager.Update(deltaTime);
		BeginDrawing();

		ClearBackground(RAYWHITE);

		DrawText("Hello, world!", 190, 200, 20, LIGHTGRAY);

		EndDrawing();
	}

	CloseWindow(); // Close the window and OpenGL context

	return 0;
}
