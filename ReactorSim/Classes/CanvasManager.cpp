#include "CanvasManager.h"
#include "Reactor/ReactorManager.h"
#include <cstdio>

CanvasManager::CanvasManager()
	: tempDial(0, 0, 200, 200, 0, 1000, 0, "TEMP °C"),
	  rpmDial(300, 0, 200, 200, 0, 3000, 0, "RPM"),
	  pressureDial(600, 0, 200, 200, 0, 60, 0, "Pressure Kpa"),
	  powerOutputDial(900, 0, 200, 200, 0, 20000, 0, "Power Output MW"),
	  fontLoaded(false) {
	// Load 7-segment font
	sevenSegmentFont = LoadFont("Resources/7segment.ttf");
	fontLoaded = sevenSegmentFont.texture.id != 0;

	coolantSlider = new Slider(
		GetScreenWidth() * 0.1f - 100,
		GetScreenHeight() * 0.6f,
		20,
		200,
		0.0f,
		1.0f,
		0.0f,
		"Coolant Valve"
	);
	controlRodSlider = new Slider(
		GetScreenWidth() * 0.5f - 100,
		GetScreenHeight() * 0.6f,
		20,
		200,
		0.0f,
		1.0f,
		1.0f,
		"Control Rods"
	);
}

CanvasManager::~CanvasManager() {
	delete coolantSlider;
	delete controlRodSlider;
	if (fontLoaded) {
		UnloadFont(sevenSegmentFont);
	}
}

void CanvasManager::RenderMainMenu() {
	ClearBackground(RAYWHITE);

	const char *title = "REACTOR SIMULATOR";
	int titleFontSize = 72;
	int titleWidth = MeasureText(title, titleFontSize);
	DrawText(title, (GetScreenWidth() - titleWidth) / 2, GetScreenHeight() / 3, titleFontSize, DARKGRAY);

	const char *prompt = "Click anywhere to start";
	int promptFontSize = 32;
	int promptWidth = MeasureText(prompt, promptFontSize);
	DrawText(prompt, (GetScreenWidth() - promptWidth) / 2, GetScreenHeight() / 2 + 50, promptFontSize, GRAY);
}

void CanvasManager::RenderIntroSequence() {
	ClearBackground(Color{240, 230, 200, 255}); // Vintage beige

	const char *line1 = "You always wanted a nuclear reactor, so you ordered one off Temu.";
	const char *line2 = "You could've sworn it was called the CANDU reactor,";
	const char *line3 = "but the label says CANDONT...";

	int fontSize = 32;
	int lineSpacing = 50;
	int startY = GetScreenHeight() / 3;

	int line1Width = MeasureText(line1, fontSize);
	int line2Width = MeasureText(line2, fontSize);
	int line3Width = MeasureText(line3, fontSize);

	DrawText(line1, (GetScreenWidth() - line1Width) / 2, startY, fontSize, DARKGRAY);
	DrawText(line2, (GetScreenWidth() - line2Width) / 2, startY + lineSpacing, fontSize, DARKGRAY);
	DrawText(line3, (GetScreenWidth() - line3Width) / 2, startY + lineSpacing * 2, fontSize, DARKGRAY);

	const char *continueText = "Click to continue...";
	int continueFontSize = 24;
	int continueWidth = MeasureText(continueText, continueFontSize);
	DrawText(continueText, (GetScreenWidth() - continueWidth) / 2, GetScreenHeight() - 100, continueFontSize, GRAY);
}

void CanvasManager::RenderPlayMode(ReactorManager *reactorManager, GameManager *gameManager, float deltaTime) {
	ClearBackground(RAYWHITE);

	if (!reactorManager) {
		return;
	}

	UpdatePlayModeControls(reactorManager, deltaTime);
	DrawPlayModeUI(deltaTime);
	DrawRevenue(reactorManager->GetRevenue());
	DrawTimer(gameManager);
}

void CanvasManager::UpdatePlayModeControls(ReactorManager *reactorManager, float deltaTime) {
	if (coolantSlider) {
		coolantSlider->Update(deltaTime);
		reactorManager->SetCoolantValve(coolantSlider->GetValue());
	}
	if (controlRodSlider) {
		controlRodSlider->Update(deltaTime);
		reactorManager->SetControlRodPosition(controlRodSlider->GetValue());
	}

	tempDial.SetValue(reactorManager->GetReactorTemp());
	rpmDial.SetValue(reactorManager->GetTurbineRPM());
	pressureDial.SetValue(reactorManager->GetReactorPressure());
	powerOutputDial.SetValue(reactorManager->GetTurbinePowerOut());
}

void CanvasManager::DrawPlayModeUI(float deltaTime) {
	tempDial.Update(deltaTime);
	rpmDial.Update(deltaTime);
	pressureDial.Update(deltaTime);
	powerOutputDial.Update(deltaTime);
}

void CanvasManager::DrawRevenue(float revenue) {
	char revenueText[64];
	snprintf(revenueText, sizeof(revenueText), "$%.2f", revenue);

	int fontSize = 48;
	Color orangeColor = {255, 140, 0, 255};

	if (fontLoaded) {
		Vector2 textSize = MeasureTextEx(sevenSegmentFont, revenueText, fontSize, 2);
		float xPos = GetScreenWidth() - textSize.x - 30;
		float yPos = 30;

		DrawTextEx(sevenSegmentFont, revenueText, {xPos, yPos}, fontSize, 2, orangeColor);

		const char *label = "REVENUE";
		DrawText(label, xPos, yPos + fontSize + 5, 20, DARKGRAY);
	} else {
		int textWidth = MeasureText(revenueText, fontSize);
		float xPos = GetScreenWidth() - textWidth - 30;
		float yPos = 30;
		DrawText(revenueText, xPos, yPos, fontSize, orangeColor);
	}
}

void CanvasManager::DrawTimer(GameManager *gameManager) {
	if (!gameManager) {
		return;
	}

	char timerText[16];
	gameManager->GetTimerFormatted(timerText, sizeof(timerText));

	int fontSize = 64;
	Color redColor = {220, 20, 20, 255};

	if (fontLoaded) {
		Vector2 textSize = MeasureTextEx(sevenSegmentFont, timerText, fontSize, 2);
		float xPos = (GetScreenWidth() - textSize.x) / 2.0f;
		float yPos = GetScreenHeight() - fontSize - 50;

		DrawTextEx(sevenSegmentFont, timerText, {xPos, yPos}, fontSize, 2, redColor);

		const char *label = "ELAPSED TIME";
		int labelWidth = MeasureText(label, 20);
		DrawText(label, (GetScreenWidth() - labelWidth) / 2, yPos - 25, 20, DARKGRAY);
	} else {
		int textWidth = MeasureText(timerText, fontSize);
		float xPos = (GetScreenWidth() - textWidth) / 2.0f;
		float yPos = GetScreenHeight() - fontSize - 50;
		DrawText(timerText, xPos, yPos, fontSize, redColor);
	}
}

void CanvasManager::RenderEndScreen(const GameStatistics &stats) {
	ClearBackground(Color{240, 230, 200, 255}); // Vintage beige

	// Title
	const char *title = stats.failureType == FailureType::MELTDOWN ? "MELTDOWN!" : "OVERPRESSURE!";
	int titleFontSize = 64;
	Color titleColor = {220, 20, 20, 255}; // Red
	int titleWidth = MeasureText(title, titleFontSize);
	DrawText(title, (GetScreenWidth() - titleWidth) / 2, 80, titleFontSize, titleColor);

	// Statistics
	int statsFontSize = 32;
	int lineSpacing = 50;
	int startY = 220;
	int centerX = GetScreenWidth() / 2;

	char buffer[128];

	// Total Time
	int totalSeconds = static_cast<int>(stats.totalTime);
	int minutes = totalSeconds / 60;
	int seconds = totalSeconds % 60;
	snprintf(buffer, sizeof(buffer), "Total Time: %02d:%02d", minutes, seconds);
	int width = MeasureText(buffer, statsFontSize);
	DrawText(buffer, centerX - width / 2, startY, statsFontSize, DARKGRAY);

	// Revenue
	snprintf(buffer, sizeof(buffer), "Revenue Earned: $%.2f", stats.revenue);
	width = MeasureText(buffer, statsFontSize);
	DrawText(buffer, centerX - width / 2, startY + lineSpacing, statsFontSize, DARKGRAY);

	// Highest Temperature (RED if caused meltdown)
	snprintf(buffer, sizeof(buffer), "Highest Temperature: %.1f C", stats.highestTemp);
	width = MeasureText(buffer, statsFontSize);
	Color tempColor = stats.failureType == FailureType::MELTDOWN ? RED : DARKGRAY;
	DrawText(buffer, centerX - width / 2, startY + lineSpacing * 2, statsFontSize, tempColor);

	// Highest Pressure (RED if caused kaboom)
	snprintf(buffer, sizeof(buffer), "Highest Pressure: %.1f kPa", stats.highestPressure);
	width = MeasureText(buffer, statsFontSize);
	Color pressureColor = stats.failureType == FailureType::OVERPRESSURE ? RED : DARKGRAY;
	DrawText(buffer, centerX - width / 2, startY + lineSpacing * 3, statsFontSize, pressureColor);

	// Average Power Output
	snprintf(buffer, sizeof(buffer), "Average Power Output: %.1f MW", stats.averagePowerOutput);
	width = MeasureText(buffer, statsFontSize);
	DrawText(buffer, centerX - width / 2, startY + lineSpacing * 4, statsFontSize, DARKGRAY);
	// Prompt to restart
	const char *restartText = "Click to return to main menu";
	int restartFontSize = 24;
	int restartWidth = MeasureText(restartText, restartFontSize);
	DrawText(restartText, (GetScreenWidth() - restartWidth) / 2, GetScreenHeight() - 80, restartFontSize, GRAY);
}
