#include "Coolant.h"

Coolant::Coolant(float maxFlow, float heatCapacity)
	: MaxFlow(maxFlow),
	  HeatCapacity(heatCapacity),
	  FlowRate(0.0f),
	  TempIn(0.0f),
	  TempOut(0.0f),
	  ThermalTransfer(0.0f) {
}

void Coolant::Update(float DeltaTime) {
	calculateThermalTransfer(DeltaTime);
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

// calculates the amount of heat units to remove and add from reactor to turbine
float Coolant::calculateThermalTransfer(float deltaTime) {
	ThermalTransfer = FlowRate * HeatCapacity * deltaTime;
}

//TODO subtract this heat from reactor and move to turbine
