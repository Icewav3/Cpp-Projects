#include "Reactor.h"
#include <cstdlib>


//todo add constsants to the constructor to allow for different reactor params, ensure defualt values for constructor for an idle state
Reactor::Reactor(float controlRodPosition, float maxTemp, float maxPressure, float maxHeatOutput)
	: ControlRodPosition(controlRodPosition)
	  , Temp(maxTemp)
	  , Pressure(maxPressure)
	  , MaxHeatOutput(maxHeatOutput) {
}

float currentTemp = 0;
float currentPressure = 0;
float currentHeatDelta = 0;

void Reactor::Update(float DeltaTime) {
	currentTemp += currentHeatDelta * DeltaTime;
}

void Reactor::UpdateControlRodPosition(float Position) {
	HeatOutput = std::abs(1 - Position) * HeatOutput;
}

float Reactor::GetPressure() {
	return Pressure;
}

float Reactor::GetTemp() {
	return Temp;
}
