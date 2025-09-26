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


	/*Reflection A2
	 *P1A - 30min - easy
	 *P1B - 45min - took me a while to figure out what it hamming distance meant, but once I did it was easy
	 *P1C - 15min - easy
	 *P2 - 3hr - hard ^note
	 *^note: This one proved very challenging as it had me run into a lot of design problems and questions, and forced
	 *me to do some more research on how best to structure things. Though I am happy with how it turned out, I would
	 *probably use a bunch of classes next time.
	 *
	 *Additional notes:
	 *Initially the bioinformatics part was very quick for me to solve, however the refactor to make a custom header file
	 *took me a bit of time since I was not fully comfortable writing headers yet. I feel with the raylib part of the
	 *assignment though, I have gotten a bunch of experience writing and updating headers,
	 *so feeling comfortable with that now.
	 *
	 *P.S. I used AI to generate the Documentation, but I also did a sanity check on what it provided.
	 *Hope that's cool, if not let me know. I find this is one use case it excels with and saves a ton of time on,
	 *since it's training data includes so many different ways people have done the same task in code.
	*/
}
