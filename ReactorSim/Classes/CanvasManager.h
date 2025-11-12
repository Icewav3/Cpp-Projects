#ifndef CPP_PROJECTS_CANVASMANAGER_H
#define CPP_PROJECTS_CANVASMANAGER_H

#include <raylib.h>
#include "Dial.h"
#include "Slider.h"

class ReactorManager; // Forward declaration

class CanvasManager {
public:
	CanvasManager(); // Default constructor
	CanvasManager(ReactorManager *reactorManager);
	~CanvasManager(); // Destructor

	void Update(float DeltaTime);
	void SetReactorManager(ReactorManager *reactorManager);

private:
	Slider *coolantSlider = nullptr;
	ReactorManager *reactorManager_ = nullptr;
};


#endif //CPP_PROJECTS_CANVASMANAGER_H
