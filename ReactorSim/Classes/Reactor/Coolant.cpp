#include "Coolant.h"

#include <algorithm>

Coolant::Coolant(float maxFlow, float heatCapacity)
	: MaxFlow(maxFlow),
	  HeatCapacity(heatCapacity),
	  FlowRate(0.0f),
	  TempIn(0.0f),
	  TempOut(0.0f),
	  ThermalTransfer(0.0f),
	  HeatExtracted(0.0f) {
}

void Coolant::Update(float DeltaTime, float reactorTemp) {
	calculateThermalTransfer(DeltaTime, reactorTemp);
}

void Coolant::UpdateCoolantValve(float Input) {
	FlowRate = Input * MaxFlow;
}

float Coolant::GetCoolantThermalTransfer() {
	return ThermalTransfer;
}

float Coolant::GetCoolantFlowRate() {
	return FlowRate;
}

float Coolant::GetCoolantTempIn() {
	return TempIn;
}

float Coolant::GetCoolantTempOut() {
	return TempOut;
}

float Coolant::GetHeatExtracted() const {
	return HeatExtracted;
}

// calculates the amount of heat units to remove and add from reactor to turbine
void Coolant::calculateThermalTransfer(float deltaTime, float reactorTemp) {
	if (FlowRate > 0.0f) {
		// Temperature difference between reactor and coolant input
		float tempDiff = std::max(0.0f, reactorTemp - TempIn);
			// Heat extracted from reactor per second
		HeatExtracted = FlowRate * HeatCapacity * tempDiff * deltaTime;

		// Update coolant output temperature
		if (FlowRate > 0.0f) {
			TempOut = TempIn + (HeatExtracted / (FlowRate * HeatCapacity * deltaTime));
		} else {
			TempOut = TempIn;
		}

		// Thermal transfer to turbine
		ThermalTransfer = HeatExtracted;
	} else {
		HeatExtracted = 0.0f;
		ThermalTransfer = 0.0f;
		TempOut = TempIn;
	}
}
