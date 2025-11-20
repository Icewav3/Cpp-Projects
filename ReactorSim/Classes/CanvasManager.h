#ifndef CPP_PROJECTS_CANVASMANAGER_H
#define CPP_PROJECTS_CANVASMANAGER_H

#include <raylib.h>
#include "Dial.h"
#include "Slider.h"
#include "GameManager.h"

class ReactorManager;

class CanvasManager {
public:
	CanvasManager();

	~CanvasManager();

	void RenderMainMenu();

	void RenderIntroSequence();

	void RenderPlayMode(ReactorManager *reactorManager, GameManager *gameManager, float deltaTime);

	void RenderEndScreen(const GameStatistics &stats);

private:
	// Play mode UI elements
	void UpdatePlayModeControls(ReactorManager *reactorManager, float deltaTime);

	void DrawPlayModeUI(float deltaTime);

	void DrawRevenue(float revenue);

	void DrawTimer(GameManager *gameManager);

	// UI Components
	Slider *coolantSlider;
	Slider *controlRodSlider;

	Dial tempDial;
	Dial rpmDial;
	Dial pressureDial;
	Dial powerOutputDial;

	Font sevenSegmentFont;
	bool fontLoaded;
};

#endif
