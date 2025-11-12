#include "CanvasManager.h"
#include "Reactor/ReactorManager.h"

CanvasManager::CanvasManager() {
	// Create a slider for coolant valve control
	coolantSlider = new Slider(
		GetScreenWidth() * 0.5f - 100, // x position
		GetScreenHeight() * 0.8f, // y position
		200, // length
		20, // width
		0.0f, // min value
		100.0f, // max value
		50.0f, // initial value
		"Coolant Valve" // label
	);
}

CanvasManager::CanvasManager(ReactorManager *reactorManager)
	: reactorManager_(reactorManager) {
	// Create a slider for coolant valve control
	coolantSlider = new Slider(
		GetScreenWidth() * 0.5f - 100, // x position
		GetScreenHeight() * 0.8f, // y position
		200, // length
		20, // width
		0.0f, // min value
		100.0f, // max value
		50.0f, // initial value
		"Coolant Valve" // label
	);
}

CanvasManager::~CanvasManager() {
	delete coolantSlider;
}

void CanvasManager::SetReactorManager(ReactorManager *reactorManager) {
	reactorManager_ = reactorManager;
}

void CanvasManager::Update(float DeltaTime) {
	// Create a dial for reactor temperature (0-1000°C)
	Dial tempDial(0, 0, 200, 200, 0, 1000, 350, "TEMP °C");
	//TODO fix length being double the value input
	Dial RPMDial(400, 0, 200, 200, 0, 1000, 350, "RPM");
	Dial ReactorPressureDial(400, 0, 200, 200, 0, 60, 40, "Pressure Kpa");

	// Update the temperature dial
	tempDial.Update(DeltaTime);
	RPMDial.Update(DeltaTime);
	ReactorPressureDial.Update(DeltaTime);

	// Update the coolant valve slider
	if (coolantSlider) {
		coolantSlider->Update(DeltaTime);
	}

	// Pass the current slider value to the ReactorManager
	if (reactorManager_ && coolantSlider) {
		reactorManager_->Update(DeltaTime, coolantSlider->GetCurrentValue());
	}
}
