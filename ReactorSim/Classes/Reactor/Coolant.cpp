#include "Coolant.h"

Coolant::Coolant(float MaxFlow) : maxFlow(MaxFlow), flowrate(0), tempIn(0), tempOut(0), ThermalTransfer(0) {
	//TODO: Initialize coolant system with maximum flow rate
}

void Coolant::Update(float DeltaTime) {
	//TODO: Update coolant temperature and flow calculations
}

void Coolant::UpdateCoolantValve(float Input) {
	//TODO: Update valve position and adjust flow rate
}
