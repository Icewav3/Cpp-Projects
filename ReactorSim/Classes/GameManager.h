#ifndef CPP_PROJECTS_GAMEMANAGER_H
#define CPP_PROJECTS_GAMEMANAGER_H

class ReactorManager;

enum class GameScene {
	MAIN_MENU,
	INTRO_SEQUENCE,
	PLAYING,
	END_SCREEN
};

enum class FailureType {
	NONE,
	MELTDOWN,
	OVERPRESSURE
};

struct GameStatistics {
	float totalTime;
	float revenue;
	float highestTemp;
	float highestPressure;
	float averagePowerOutput;
	FailureType failureType;

	GameStatistics()
		: totalTime(0.0f)
		  , revenue(0.0f)
		  , highestTemp(0.0f)
		  , highestPressure(0.0f)
		  , averagePowerOutput(0.0f)
		  , failureType(FailureType::NONE) {
	}
};

class GameManager {
public:
	GameManager();

	void Update(float deltaTime, ReactorManager *reactorManager);

	void Reset();

	// Scene management
	GameScene GetCurrentScene() const;

	void SetScene(GameScene scene);

	// Timer methods
	float GetElapsedTime() const;

	bool IsTimerRunning() const;

	void GetTimerFormatted(char *buffer, int bufferSize) const;

	// Statistics
	const GameStatistics &GetStatistics() const;

private:
	void UpdateStatistics(ReactorManager *reactorManager, float deltaTime);

	void FinalizeStatistics(ReactorManager *reactorManager);

	GameScene currentScene;
	float elapsedTime;
	bool timerRunning;
	const float POWER_THRESHOLD = 100.0f;

	// Statistics tracking
	GameStatistics stats;
	float totalPowerAccumulated;
	int powerSampleCount;
};

#endif //CPP_PROJECTS_GAMEMANAGER_H
