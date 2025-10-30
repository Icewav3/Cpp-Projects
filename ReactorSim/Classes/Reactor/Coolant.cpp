#include "Coolant.h"

Coolant::Coolant(float maxFlow)
	: MaxFlow(maxFlow)
	  , FlowRate(0.0f)
	  , TempIn(0.0f)
	  , TempOut(0.0f)
	  , ThermalTransfer(0.0f) {
}

void Coolant::Update(float DeltaTime) {
	//TODO: Update coolant temperature and flow calculations
}

void Coolant::UpdateCoolantValve(float Input) {
	//TODO: Update valve position and adjust flow rate
}

float Coolant::calculateThermalTransfer() {
	ThermalTransfer =
}
