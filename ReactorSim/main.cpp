#include <iostream>
#include "raylib.h"
#include "Classes/CanvasManager.h"
#include "Classes/Reactor/ReactorManager.h"
#include "Classes/GameManager.h"

int main() {
	// Initialize the window
	const int screenWidth = GetMonitorWidth(0);
	const int screenHeight = GetMonitorHeight(0);

	InitWindow(screenWidth, screenHeight, "Reactor Simulator");
	SetTargetFPS(60);

	// Create managers
	GameManager gameManager;
	CanvasManager canvasManager;
	ReactorManager *reactorManager = nullptr;

	while (!WindowShouldClose()) {
		float deltaTime = GetFrameTime();

		// Handle scene transitions
		GameScene currentScene = gameManager.GetCurrentScene();

		// Input handling for scene transitions
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			switch (currentScene) {
				case GameScene::MAIN_MENU:
					gameManager.SetScene(GameScene::INTRO_SEQUENCE);
					break;

				case GameScene::INTRO_SEQUENCE:
					// Create new reactor for play mode
					if (reactorManager) delete reactorManager;
					reactorManager = new ReactorManager();
					gameManager.Reset();
					gameManager.SetScene(GameScene::PLAYING);
					break;

				case GameScene::END_SCREEN:
					// Clean up and return to menu
					if (reactorManager) {
						delete reactorManager;
						reactorManager = nullptr;
					}
					gameManager.Reset();
					break;

				case GameScene::PLAYING:
					// No click action during play
					break;
			}
		}

		// Update game logic
		if (currentScene == GameScene::PLAYING && reactorManager) {
			gameManager.Update(deltaTime, reactorManager);
			reactorManager->Update(deltaTime);
		}

		// Render
		BeginDrawing();

		switch (currentScene) {
			case GameScene::MAIN_MENU:
				canvasManager.RenderMainMenu();
				break;

			case GameScene::INTRO_SEQUENCE:
				canvasManager.RenderIntroSequence();
				break;

			case GameScene::PLAYING:
				if (reactorManager) {
					canvasManager.RenderPlayMode(reactorManager, &gameManager, deltaTime);
				}
				break;

			case GameScene::END_SCREEN:
				canvasManager.RenderEndScreen(gameManager.GetStatistics());
				break;
		}
		EndDrawing();
	}

	// Cleanup
	if (reactorManager) {
		delete reactorManager;
	}

	CloseWindow();
	return 0;
}
