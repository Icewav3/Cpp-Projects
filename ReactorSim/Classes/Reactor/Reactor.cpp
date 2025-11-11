#include "Reactor.h"
#include <cstdlib>


//todo add constsants to the constructor to allow for different reactor params, ensure defualt values for constructor for an idle state
Reactor::Reactor(float controlRodPosition, float temp, float pressure, float heatOutput)
	: ControlRodPosition(controlRodPosition)
	  , Temp(temp)
	  , Pressure(pressure)
	  , HeatOutput(heatOutput) {
}

float maxTemp = 1000;

void Reactor::Update(float DeltaTime) {
}

void Reactor::UpdateControlRodPosition(float Position) {
	HeatOutput = std::abs(1 - Position) * maxTemp;
}

float Reactor::GetPressure() {
	//TODO: Return current reactor pressure
	return Pressure;
}

float Reactor::GetTemp() {
	return Temp;
}

float Reactor::GetHeatOutput() {
	//TODO: Calculate and return steam output
	return HeatOutput;
}
