#include "ReactorManager.h"

ReactorManager::ReactorManager()
	: reactor(new Reactor(1000.0f, 20.0f, 5000.0f))
	  , turbine(new Turbine(3000, 10000, 2.0f))
	  , coolant(new Coolant(100.0f, 0.1f))
	  , TotalRevenue(0.0f)
	  , RevenueRate(0.1f) {
	// $0.10 per MW-second
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

float ReactorManager::GetRevenue() const {
	return TotalRevenue;
}

bool ReactorManager::IsMeltdown() const {
	return reactor->IsMeltdown();
}

bool ReactorManager::IsKaboom() const {
	return reactor->IsKaboom();
}

void ReactorManager::SetControlRodPosition(float Position) {
	reactor->UpdateControlRodPosition(Position);
}

void ReactorManager::SetCoolantValve(float Position) {
	coolant->UpdateCoolantValve(Position);
}

void ReactorManager::Update(float DeltaTime) {
	// 1. Update reactor (generates heat)
	reactor->Update(DeltaTime);

	// 2. Update coolant (calculates heat transfer based on reactor temp)
	coolant->Update(DeltaTime, reactor->GetTemp());

	// 3. Coolant removes heat from reactor
	float heatExtracted = coolant->GetHeatExtracted();
	reactor->RemoveHeat(heatExtracted);
	// 4. Coolant passes heat to turbine
	float thermalTransfer = coolant->GetCoolantThermalTransfer();
	turbine->Update(DeltaTime, thermalTransfer);

	// 5. Turbine converts heat to power (heat is consumed/deleted)
	float powerOutput = turbine->GetPowerOut();

	// 6. Power generates revenue
	TotalRevenue += powerOutput * RevenueRate * DeltaTime;
}
