#include "Reactor.h"
#include <cstdlib>


Reactor::Reactor(float maxTemp, float maxPressure, float maxHeatOutput)
	: MaxTemp(maxTemp)
	  , MaxPressure(maxPressure)
	  , MaxHeatOutput(maxHeatOutput)
	  , ControlRodPosition(1.0f)
	  , HeatOutput(0.0f)
	  , currentTemp(20.0f)
	  , currentPressure(1.0f)
	  , currentHeatDelta(0.0f)
	  , meltdown(false)
	  , kaboom(false) {
}

void Reactor::Update(float DeltaTime) {
	// heat calc
	currentHeatDelta = HeatOutput;
	currentTemp += currentHeatDelta * DeltaTime;

	// basic pressure calc
	currentPressure = 1.0f + (currentTemp - 20.0f) * 0.1f;

	if (currentTemp > MaxTemp) {
		meltdown = true;
	}
	if (currentPressure > MaxPressure) {
		kaboom = true;
	}
}

void Reactor::UpdateControlRodPosition(float Position) {
	ControlRodPosition = Position;
	// When rods are fully inserted (1.0), no heat output
	// When rods are withdrawn (0.0), maximum heat output
	HeatOutput = (1.0f - Position) * MaxHeatOutput;
}

float Reactor::GetPressure() {
	return currentPressure;
}

float Reactor::GetTemp() {
	return currentTemp;
}
