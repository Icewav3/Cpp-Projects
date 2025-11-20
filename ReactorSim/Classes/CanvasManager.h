#ifndef CPP_PROJECTS_CANVASMANAGER_H
#define CPP_PROJECTS_CANVASMANAGER_H

#include <raylib.h>
#include "Dial.h"
#include "Slider.h"
#include "GameManager.h"

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

	void DrawRevenue();

	void DrawTimer();

	Slider *coolantSlider;
	Slider *controlRodSlider;
	ReactorManager *reactorManager_;
	GameManager *gameManager_;

	Dial tempDial;
	Dial rpmDial;
	Dial pressureDial;
	Dial powerOutputDial;

	Font sevenSegmentFont;
	bool fontLoaded;

	bool isFucked = false;
};

#endif
