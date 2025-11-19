#include <iostream>

// Add raylib header
#include "raylib.h"
#include "Classes/CanvasManager.h"
#include "Classes/Reactor/ReactorManager.h"

int main() {
	// Initialize the window TODO may need to refactor for web iframes
	const int screenWidth = GetMonitorWidth(0);
	const int screenHeight = GetMonitorHeight(0);

	InitWindow(screenWidth, screenHeight, "raylib empty window example");

	SetTargetFPS(60); // Set our game to run at 60 frames-per-second

	// Create reactor manager and canvas manager
	ReactorManager reactorManager;
	CanvasManager canvasManager;
	canvasManager.SetReactorManager(&reactorManager);

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
