#include "Reactor.h"

#include <algorithm>
#include <cstdlib>


Reactor::Reactor(float maxTemp, float maxPressure, float maxHeatOutput)
	: MaxTemp(maxTemp)
	  , MaxPressure(maxPressure)
	  , MaxHeatOutput(maxHeatOutput)
	  , ControlRodPosition(1.0f)
	  , TargetControlRodPosition(1.0f)
	  , HeatOutput(0.1f)
	  , currentTemp(20.0f)
	  , currentPressure(1.0f)
	  , currentHeatDelta(0.0f)
	  , meltdown(false)
	  , kaboom(false) {
}

void Reactor::Update(float DeltaTime) {
	// control rod lag

	float rodSpeed = 0.25f; //magic number prolly move me
	float positionDifference = TargetControlRodPosition - ControlRodPosition;
	ControlRodPosition += positionDifference * rodSpeed * DeltaTime;
	// RUNAWAY REACTION BABY >:)
	float reactivity = 0.7f - ControlRodPosition;
	float changeInHeat = HeatOutput * reactivity * 2.0f * DeltaTime;

	HeatOutput += changeInHeat;

	if (HeatOutput < 0.1f) {
		HeatOutput = 0.1f;
	}
	if (HeatOutput > MaxHeatOutput) {
		HeatOutput = MaxHeatOutput;
	}
	// heat calc - adds heat from fission
	currentTemp += HeatOutput * DeltaTime;
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
	TargetControlRodPosition = Position;
}

float Reactor::GetPressure() {
	return currentPressure;
}

float Reactor::GetTemp() {
	return currentTemp;
}

float Reactor::GetHeatOutput() const {
	return HeatOutput;
}

void Reactor::RemoveHeat(float heatAmount) {
	// Coolant removes heat from reactor
	currentTemp -= heatAmount;
	if (currentTemp < 20.0f) {
		currentTemp = 20.0f; // Minimum ambient temp
	}
}

bool Reactor::IsMeltdown() const {
	return meltdown;
}

bool Reactor::IsKaboom() const {
	return kaboom;
}
