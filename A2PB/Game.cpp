#include "Game.hpp"
#include <raylib.h>

#include "ControlPanelWidget.h"

int main() {
	// Initialize raylib window
	constexpr int W = 1280;
	constexpr int H = 720;


	InitWindow(W, H, "Raylib Game Window");
	SetTargetFPS(60);
	WidgetPosition buttonPos = {200, 100, 80, 40};
	WidgetPosition indicatorPos = {300, 100, 80, 40};
	DisplayIndicator HeatWarning(indicatorPos, MakeColors(RED, MAROON, YELLOW), false, "HEAT", 0.75);
	Button CoolantButton(buttonPos, MakeColors(GREEN, RED, BLACK), false, true);
	// Main game loop
	while (!WindowShouldClose()) {
		Color Background = {255, 241, 166, 255};
		// Draw
		BeginDrawing();
		ClearBackground(Background);
		CoolantButton.Update();
		HeatWarning.SetValue(!CoolantButton.GetValue());
		HeatWarning.Update();
		// Draw labels
		DrawText("Coolant", 200, 80, 20, BLACK);
		DrawText("OVERHEATING:", 300, 80, 20, BLACK);
		EndDrawing();
	}

	// Clean up
	CloseWindow();

	return 0;
}
