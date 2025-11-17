#include "CanvasManager.h"

#include <cmath>

#include "Reactor/ReactorManager.h"

CanvasManager::CanvasManager(ReactorManager *reactorManager)
	: reactorManager_(reactorManager),
	  tempDial(0, 0, 200, 200, 0, 1000, 350, "TEMP °C"),
	  rpmDial(300, 0, 200, 200, 0, 1000, 350, "RPM"),
	  pressureDial(600, 0, 200, 200, 0, 60, 40, "Pressure Kpa"),
	  powerOutputDial(900, 0, 200, 200, 0, 1000, 750, "Power Output Mw") {
	CreateSlider();
}

CanvasManager::~CanvasManager() {
	delete coolantSlider;
}

void CanvasManager::CreateSlider() {
	coolantSlider = new Slider(
		GetScreenWidth() * 0.5f - 100,
		GetScreenHeight() * 0.8f,
		20,
		200,
		0.0f,
		100.0f,
		50.0f,
		"Coolant Valve"
	);
}

void CanvasManager::SetReactorManager(ReactorManager *reactorManager) {
	reactorManager_ = reactorManager;
}

void CanvasManager::Update(float deltaTime) {
	tempDial.Update(deltaTime);
	rpmDial.Update(deltaTime);
	pressureDial.Update(deltaTime);
	powerOutputDial.Update(deltaTime);
	static float accumulated = 0.0f;
	accumulated += 1;
	powerOutputDial.SetTargetValue(std::fmod(accumulated, 1000.0f));

	if (coolantSlider) {
		coolantSlider->Update(deltaTime);
	}

	if (reactorManager_ && coolantSlider) {
		reactorManager_->Update(deltaTime, coolantSlider->GetValue());
	}
}
