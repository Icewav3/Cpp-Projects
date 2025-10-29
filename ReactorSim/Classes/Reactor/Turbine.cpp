#include "Turbine.h"

Turbine::Turbine(int maxRPM, int maxElectricityOut, float RPMtoElectricCharge)
	: MaxRPM(maxRPM)
	  , MaxElectricityOut(maxElectricityOut)
	  , RPMtoElectricCharge(RPMtoElectricCharge)
	  , RPM(0.0f)
	  , PowerOut(0.0f) {
}

void Turbine::Update(float DeltaTime) {
}

void Turbine::CalculateRPM() {
}

void Turbine::CalculatePowerOut() {
}
