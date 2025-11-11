#include "ReactorManager.h"

ReactorManager::ReactorManager()
	: reactor(new Reactor(0.5f, 350.0f, 100.0f, 1000.0f))
	  , turbine(new Turbine(3000, 1000, 0.001f))
	  , coolant(new Coolant(100.0f)) {
}

ReactorManager::~ReactorManager() {
	delete reactor;
	delete turbine;
	delete coolant;
}

void ReactorManager::Update(float DeltaTime, float userInput) {
	// Update all components
	reactor->Update(DeltaTime);
	turbine->Update(DeltaTime);
	coolant->Update(DeltaTime);

	// Pass data between systems
	float heatOutput = reactor->GetHeatOutput();
	coolant->UpdateCoolantValve(userInput);

	float coolantFlowRate = coolant->GetCoolantFlowRate();
	turbine->Update(coolantFlowRate);

	float turbineRPM = turbine->GetRPM();
	reactor->UpdateControlRodPosition(turbineRPM);
}

float ReactorManager::GetReactorTemp() const {
	return reactor->GetTemp();
}

float ReactorManager::GetCoolantTemp() const {
	return coolant->GetCoolantTempOut();
}

float ReactorManager::GetTurbineRPM() const {
	return turbine->GetRPM();
}

float ReactorManager::GetTurbinePowerOut() const {
	return turbine->GetPowerOut();
}
