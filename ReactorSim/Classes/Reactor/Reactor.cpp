#include "Reactor.h"

void Reactor::Update(float DeltaTime) {
	//TODO: Update reactor temperature, pressure, and heat output based on control rod position
}

void Reactor::UpdateCtrlRodPos(float NewPos) {
	//TODO: Update control rod position and recalculate reactor parameters
}

float Reactor::getPressure() {
	//TODO: Return current reactor pressure
	return pressure;
}

float Reactor::getTemp() {
	//TODO: Return current reactor temperature
	return temp;
}

float Reactor::getSteamOut() {
	//TODO: Calculate and return steam output based on current reactor conditions
	return heat_output;
}
