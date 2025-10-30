#include "Reactor.h"

Reactor::Reactor(float controlRodPosition, float temp, float pressure, float heatOutput)
	: ControlRodPosition(controlRodPosition)
	  , Temp(temp)
	  , Pressure(pressure)
	  , HeatOutput(heatOutput) {
}

void Reactor::Update(float DeltaTime) {
	//TODO: Update reactor core temperature and pressure calculations
}

void Reactor::UpdateControlRodPosition(float Position) {
	//TODO: Update control rod position and affect reactor behavior
}

float Reactor::GetPressure() {
	//TODO: Return current reactor pressure
	return Pressure;
}

float Reactor::GetTemp() {
	//TODO: Return current reactor temperature
	return Temp;
}

float Reactor::GetHeatOutput() {
	//TODO: Calculate and return steam output
	return HeatOutput;
}
