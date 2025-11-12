#include "CanvasManager.h"

void CanvasManager::Update(float DeltaTime) {
	// Create a dial for reactor temperature (0-1000°C)
	Dial tempDial(0, 0, 200, 200, 0, 1000, 350, "TEMP °C");
	//TODO fix length being double the value input
	Dial RPMDial(400, 0, 200, 200, 0, 1000, 350, "RPM");
	Dial ReactorPressureDial(400, 0, 200, 200, 0, 1000, 350, "RPM");

	// In game loop
	tempDial.Update(DeltaTime);
	RPMDial.Update(DeltaTime);
	ReactorPressureDial.Update(DeltaTime);
}
