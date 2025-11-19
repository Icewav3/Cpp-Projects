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

	void UpdateValues(float deltaTime);

	void UpdateUI(float deltaTime);

	void SetReactorManager(ReactorManager *reactorManager);

private:
	Slider *coolantSlider;
	Slider *controlRodSlider;
	ReactorManager *reactorManager_;

	Dial tempDial;
	Dial rpmDial;
	Dial pressureDial;
	Dial powerOutputDial;


	void CreateSlider();
};

#endif
