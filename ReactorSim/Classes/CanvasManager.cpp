#include "CanvasManager.h"

#include <cmath>

#include "Reactor/ReactorManager.h"

CanvasManager::CanvasManager(ReactorManager *reactorManager)
	: reactorManager_(reactorManager),
	  tempDial(0, 0, 200, 200, 0, 1000, 350, "TEMP °C"),
	  rpmDial(300, 0, 200, 200, 0, 1000, 350, "RPM"),
	  pressureDial(600, 0, 200, 200, 0, 60, 40, "Pressure Kpa"),
	  powerOutputDial(900, 0, 200, 200, 0, 1000, 750, "Power Output Mw") {
	coolantSlider = new Slider(
		GetScreenWidth() * 0.1f - 100,
		GetScreenHeight() * 0.6f,
		20,
		200,
		0.0f,
		100.0f,
		50.0f,
		"Control Rods"
	);
	controlRodSlider = new Slider(
		GetScreenWidth() * 0.5f - 100,
		GetScreenHeight() * 0.6f,
		20,
		200,
		0.0f,
		100.0f,
		50.0f,
		"Coolant Valve"
	);
}

CanvasManager::~CanvasManager() {
	delete coolantSlider;
	delete controlRodSlider;
}

void CanvasManager::Update(float deltaTime) {
	UpdateValues(deltaTime);
	UpdateUI(deltaTime);
}

void CanvasManager::SetReactorManager(ReactorManager *reactorManager) {
	reactorManager_ = reactorManager;
}

void CanvasManager::UpdateValues(float deltaTime) {
	//UI Elements
	if (reactorManager_ && coolantSlider) {
		coolantSlider->Update(deltaTime);
		reactorManager_->SetCoolantValve(coolantSlider->GetValue());
	}
	if (reactorManager_ && controlRodSlider) {
		controlRodSlider->Update(deltaTime);
		reactorManager_->SetControlRodPosition(controlRodSlider->GetValue());
	}
	reactorManager_->Update(deltaTime);
}

void CanvasManager::UpdateUI(float deltaTime) {
	tempDial.Update(deltaTime);
	rpmDial.Update(deltaTime);
	pressureDial.Update(deltaTime);
	powerOutputDial.Update(deltaTime);
}
