#include "Game.hpp"
#include <raylib.h>

#include "ControlPanelWidget.h"

int main() {
	// Initialize raylib window
	constexpr int W = 800;
	constexpr int H = 400;


	InitWindow(W, H, "Raylib Game Window");
	SetTargetFPS(60);
	WidgetPosition buttonPos = {200, 100, 80, 40};
	WidgetPosition indicatorPos = {300, 100, 80, 40};
	WidgetPosition sliderPos = {200, 200, 150, 30};
	WidgetPosition dialPos = {500, 150, 100, 100};

	DisplayIndicator HeatWarning(indicatorPos, MakeColors(RED, MAROON, YELLOW), false, "HEAT", 0.75);
	Button CoolantButton(buttonPos, MakeColors(GREEN, RED, BLACK), false, true);
	Slider TurbineSpeedSlider(sliderPos, MakeColors(BLUE, LIGHTGRAY, BLACK), 50.0f, 0.0f, 100.0f);
	RadialDial TemperatureDial(dialPos, MakeColors(RED, LIGHTGRAY, BLACK), 50.0f, 0.0f, 100.0f);
	// Main game loop
	while (!WindowShouldClose()) {
		Color Background = {255, 241, 166, 255};
		// Draw
		BeginDrawing();
		ClearBackground(Background);
		CoolantButton.Update();
		HeatWarning.SetValue(!CoolantButton.GetValue());
		HeatWarning.Update();

		TurbineSpeedSlider.Update();

		// Temp = inverse of turbine speed for now
		float turbineSpeed = TurbineSpeedSlider.getValue();
		float temperature = 100.0f - turbineSpeed;
		TemperatureDial.SetValue(temperature);
		TemperatureDial.Update();

		// Draw labels
		DrawText("Coolant", 200, 80, 20, BLACK);
		DrawText("OVERHEATING:", 300, 80, 20, BLACK);
		DrawText("Turbine Speed", 200, 180, 20, BLACK);
		DrawText("Temperature", 500, 130, 20, BLACK);

		// Display current values
		DrawText(TextFormat("Speed: %.1f%%", turbineSpeed), 200, 240, 20, BLACK);
		DrawText(TextFormat("Temp: %.1f°C", temperature), 500, 260, 20, BLACK);
		EndDrawing();
	}

	// Clean up
	CloseWindow();

	return 0;
}
