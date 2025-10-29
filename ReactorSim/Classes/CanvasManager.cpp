#include "CanvasManager.h"

void CanvasManager::Update(float DeltaTime) {
	// Create a dial for reactor temperature (0-1000°C)
	Dial tempDial(50, 50, 200, 200, 0, 1000, 350, "TEMP °C");

	// In game loop
	tempDial.Update(DeltaTime);
}
