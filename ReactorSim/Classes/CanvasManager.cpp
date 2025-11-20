#include "CanvasManager.h"

#include <cmath>
#include <cstdio>

#include "Reactor/ReactorManager.h"

CanvasManager::CanvasManager(ReactorManager *reactorManager)
	: reactorManager_(reactorManager),
	  gameManager_(new GameManager()),
	  tempDial(0, 0, 200, 200, 0, 1000, 0, "TEMP °C"),
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
	delete gameManager_;
	if (fontLoaded) {
		UnloadFont(sevenSegmentFont);
	}
}

void CanvasManager::Update(float deltaTime) {
	if (!isFucked) {
		UpdateValues(deltaTime);
		UpdateUI(deltaTime);
	}

	// Draw UI elements
	DrawRevenue();
	DrawTimer();
}

void CanvasManager::SetReactorManager(ReactorManager *reactorManager) {
	reactorManager_ = reactorManager;
}

void CanvasManager::UpdateValues(float deltaTime) {
	//UI Elements
	if (!reactorManager_) {
		return;
	}

	// Update game manager
	gameManager_->Update(deltaTime, reactorManager_);
	// Check for game over
	if (gameManager_->IsGameOver()) {
		isFucked = true;
	}

	if (coolantSlider) {
		coolantSlider->Update(deltaTime);
		reactorManager_->SetCoolantValve(coolantSlider->GetValue());
	}
	if (controlRodSlider) {
		controlRodSlider->Update(deltaTime);
		reactorManager_->SetControlRodPosition(controlRodSlider->GetValue());
	}
	reactorManager_->Update(deltaTime);
	tempDial.SetValue(reactorManager_->GetReactorTemp());
	rpmDial.SetValue(reactorManager_->GetTurbineRPM());
	pressureDial.SetValue(reactorManager_->GetReactorPressure());
	powerOutputDial.SetValue(reactorManager_->GetTurbinePowerOut());
}

void CanvasManager::UpdateUI(float deltaTime) {
	tempDial.Update(deltaTime);
	rpmDial.Update(deltaTime);
	pressureDial.Update(deltaTime);
	powerOutputDial.Update(deltaTime);
}

void CanvasManager::DrawRevenue() {
	if (!reactorManager_) {
		return;
	}

	char revenueText[64];
	snprintf(revenueText, sizeof(revenueText), "$%.2f", reactorManager_->GetRevenue());

	int fontSize = 48;
	Color orangeColor = {255, 140, 0, 255};

	if (fontLoaded) {
		Vector2 textSize = MeasureTextEx(sevenSegmentFont, revenueText, fontSize, 2);
		float xPos = GetScreenWidth() - textSize.x - 30; // 30px padding from right
		float yPos = 30; // 30px from top

		DrawTextEx(sevenSegmentFont, revenueText, {xPos, yPos}, fontSize, 2, orangeColor);

		// Label below revenue
		const char *label = "REVENUE";
		DrawText(label, xPos, yPos + fontSize + 5, 20, DARKGRAY);
	} else {
		// Fallback to default font
		int textWidth = MeasureText(revenueText, fontSize);
		float xPos = GetScreenWidth() - textWidth - 30;
		float yPos = 30;
		DrawText(revenueText, xPos, yPos, fontSize, orangeColor);
	}
}

void CanvasManager::DrawTimer() {
	if (!gameManager_) {
		return;
	}

	char timerText[16];
	gameManager_->GetTimerFormatted(timerText, sizeof(timerText));

	int fontSize = 64;
	Color redColor = {220, 20, 20, 255};

	if (fontLoaded) {
		Vector2 textSize = MeasureTextEx(sevenSegmentFont, timerText, fontSize, 2);
		float xPos = (GetScreenWidth() - textSize.x) / 2.0f; // Centered horizontally
		float yPos = GetScreenHeight() - fontSize - 50; // 50px from bottom

		DrawTextEx(sevenSegmentFont, timerText, {xPos, yPos}, fontSize, 2, redColor);

		// Label above timer
		const char *label = "ELAPSED TIME";
		int labelWidth = MeasureText(label, 20);
		DrawText(label, (GetScreenWidth() - labelWidth) / 2, yPos - 25, 20, DARKGRAY);
	} else {
		// Fallback to default font
		int textWidth = MeasureText(timerText, fontSize);
		float xPos = (GetScreenWidth() - textWidth) / 2.0f;
		float yPos = GetScreenHeight() - fontSize - 50;
		DrawText(timerText, xPos, yPos, fontSize, redColor);
	}
}
