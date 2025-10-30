#include "ReactorManager.h"

void ReactorManager::Update(float DeltaTime) {
	//TODO: Update reactor, turbine, and coolant systems
	reactor->Update(DeltaTime);  // TODO: Add proper delta time
	turbine->Update(DeltaTime);  // TODO: Add proper delta time
	coolant->Update(DeltaTime);  // TODO: Add proper delta time
}