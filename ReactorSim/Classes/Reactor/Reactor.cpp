#include "Reactor.h"
#include <cstdlib>


//todo add constants to the constructor to allow for different reactor params, ensure default values for constructor for an idle state
Reactor::Reactor(float maxTemp, float maxPressure, float maxHeatOutput)
	: MaxTemp(maxTemp)
	  , MaxPressure(maxPressure)
	  , MaxHeatOutput(maxHeatOutput) {
}

bool meltdown = false;
bool kaboom = false;
float currentPosition = 0;
float currentTemp = 0;
float currentPressure = 0;
float currentHeatDelta = 0;

void Reactor::Update(float DeltaTime) {
	currentTemp += currentHeatDelta * DeltaTime;
	if (currentTemp > MaxTemp) {
		meltdown = true;
	}
	if (currentPressure > MaxPressure) {
		kaboom = true;
	}
}

void Reactor::UpdateControlRodPosition(float Position) {
	HeatOutput = std::abs(1 - Position) * HeatOutput;
}

float Reactor::GetPressure() {
	return MaxPressure;
}

float Reactor::GetTemp() {
	return MaxTemp;
}
