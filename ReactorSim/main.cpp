#include <iostream>

// Add raylib header
#include "raylib.h"
#include "Classes/CanvasManager.h"
#include "Classes/Reactor/ReactorManager.h"

int main() {
	// Initialize the window
	const int screenWidth = GetMonitorWidth(0);
	const int screenHeight = GetMonitorHeight(0);

	InitWindow(screenWidth, screenHeight, "Reactor Simulator");

	SetTargetFPS(60); // Set our game to run at 60 frames-per-second

	// Create reactor manager and canvas manager
	ReactorManager reactorManager;
	CanvasManager canvasManager;
	canvasManager.SetReactorManager(&reactorManager);

	while (!WindowShouldClose()) {
		float deltaTime = GetFrameTime();

		BeginDrawing();
		ClearBackground(RAYWHITE);

		// Update and draw everything
		canvasManager.Update(deltaTime);

		EndDrawing();
	}

	CloseWindow(); // Close the window and OpenGL context

	return 0;
}
