#include "CanvasManager.h"

#include <cmath>

#include "Reactor/ReactorManager.h"

CanvasManager::CanvasManager(ReactorManager *reactorManager)
	: reactorManager_(reactorManager),
	  tempDial(0, 0, 200, 200, 0, 1000, 0, "TEMP °C"),
	  rpmDial(300, 0, 200, 200, 0, 1000, 0, "RPM"),
	  pressureDial(600, 0, 200, 200, 0, 60, 0, "Pressure Kpa"),
	  powerOutputDial(900, 0, 200, 200, 0, 10000, 0, "Power Output Mw") {
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
}

void CanvasManager::Update(float deltaTime) {
	if (!isFucked) {
		UpdateValues(deltaTime);
		UpdateUI(deltaTime);
	}
	//TODO KYS
}

void CanvasManager::SetReactorManager(ReactorManager *reactorManager) {
	reactorManager_ = reactorManager;
}

void CanvasManager::UpdateValues(float deltaTime) {
	//UI Elements
	if (!reactorManager_) {
		return;
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
