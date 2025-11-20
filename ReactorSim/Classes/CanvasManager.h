#ifndef CPP_PROJECTS_CANVASMANAGER_H
#define CPP_PROJECTS_CANVASMANAGER_H

#include <raylib.h>
#include "Dial.h"
#include "Slider.h"

class ReactorManager;

class CanvasManager {
public:
	CanvasManager(ReactorManager *reactorManager = nullptr);

	~CanvasManager();

	void Update(float deltaTime);

	void SetReactorManager(ReactorManager *reactorManager);

private:
	void UpdateValues(float deltaTime);

	void UpdateUI(float deltaTime);

	Slider *coolantSlider;
	Slider *controlRodSlider;
	ReactorManager *reactorManager_;

	Dial tempDial;
	Dial rpmDial;
	Dial pressureDial;
	Dial powerOutputDial;

	bool isFucked = false;

	void CreateSlider();
};

#endif
