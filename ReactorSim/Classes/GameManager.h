#ifndef CPP_PROJECTS_GAMEMANAGER_H
#define CPP_PROJECTS_GAMEMANAGER_H

class ReactorManager;

class GameManager {
public:
	GameManager();

	void Update(float deltaTime, ReactorManager *reactorManager);

	float GetElapsedTime() const;

	bool IsTimerRunning() const;

	bool IsGameOver() const;

	void GetTimerFormatted(char *buffer, int bufferSize) const;

private:
	float elapsedTime;
	bool timerRunning;
	bool gameOver;
	const float POWER_THRESHOLD = 100.0f; // MW threshold to start timer
};

#endif //CPP_PROJECTS_GAMEMANAGER_H
