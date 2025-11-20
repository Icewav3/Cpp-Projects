#include "ReactorManager.h"

ReactorManager::ReactorManager()
	: reactor(new Reactor(1000.0f, 20.0f, 500.0f))
	  , turbine(new Turbine(3000, 10000, 2.0f))
	  , coolant(new Coolant(100.0f, 100.0f)) {
}

ReactorManager::~ReactorManager() {
	delete reactor;
	delete turbine;
	delete coolant;
}

float ReactorManager::GetReactorTemp() const {
	return reactor->GetTemp();
}

float ReactorManager::GetReactorPressure() const {
	return reactor->GetPressure();
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

void ReactorManager::SetControlRodPosition(float Position) {
	reactor->UpdateControlRodPosition(Position);
}

void ReactorManager::SetCoolantValve(float Position) {
	coolant->UpdateCoolantValve(Position);
}

void ReactorManager::Update(float DeltaTime) {
	// Update all components
	reactor->Update(DeltaTime);
	turbine->Update(DeltaTime);
	coolant->Update(DeltaTime);

	// Pass data between systems
	//TODO
}
