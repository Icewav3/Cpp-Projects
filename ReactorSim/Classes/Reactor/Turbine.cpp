#include "Turbine.h"
#include <algorithm>

Turbine::Turbine(int maxRPM, int maxElectricityOut, float RPMtoElectricCharge)
	: MaxRPM(maxRPM)
	  , MaxElectricityOut(maxElectricityOut)
	  , RPMtoElectricCharge(RPMtoElectricCharge)
	  , RPM(0.0f)
	  , PowerOut(0.0f)
	  , CurrentHeatInput(0.0f) {
}

void Turbine::Update(float DeltaTime, float heatInput) {
	CurrentHeatInput = heatInput;
	CalculateRPM(DeltaTime);
	CalculatePowerOut();
}

float Turbine::GetRPM() {
	return RPM;
}

float Turbine::GetPowerOut() {
	return PowerOut;
}

//TODO HMMM
void Turbine::CalculateRPM(float deltaTime) {
	// Convert heat input to RPM (simplified model)
	// Heat input directly drives turbine speed
	float targetRPM = (CurrentHeatInput / 100.0f) * MaxRPM;
	targetRPM = std::min(targetRPM, static_cast<float>(MaxRPM));

	// Smooth RPM changes (ramp up/down)
	float rpmChange = (targetRPM - RPM) * 2.0f * deltaTime; // 2.0 = response rate
	RPM += rpmChange;
	RPM = std::clamp(RPM, 0.0f, static_cast<float>(MaxRPM));
}

void Turbine::CalculatePowerOut() {
	// Convert RPM to electrical power output (MW)
	PowerOut = (RPM / static_cast<float>(MaxRPM)) * MaxElectricityOut * RPMtoElectricCharge;
	PowerOut = std::clamp(PowerOut, 0.0f, static_cast<float>(MaxElectricityOut));
}
