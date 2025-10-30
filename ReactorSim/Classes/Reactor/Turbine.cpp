#include "Turbine.h"
#include "Turbine.h"

Turbine::Turbine(int maxRPM, int maxElectricityOut, float RPMtoElectricCharge)
	: MaxRPM(maxRPM)
	  , MaxElectricityOut(maxElectricityOut)
	  , RPMtoElectricCharge(RPMtoElectricCharge)
	  , RPM(0.0f)
	  , PowerOut(0.0f) {
}

void Turbine::Update(float DeltaTime) {
	//TODO: Update turbine state based on steam input
	CalculateRPM();
	CalculatePowerOut();
}

void Turbine::CalculateRPM() {
	//TODO: Calculate RPM based on steam input
}

void Turbine::CalculatePowerOut() {
	//TODO: Calculate electricity output based on RPM
}
