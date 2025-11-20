#include "GameManager.h"
#include "Reactor/ReactorManager.h"
#include <cstdio>

GameManager::GameManager()
	: elapsedTime(0.0f)
	  , timerRunning(false)
	  , gameOver(false) {
}

void GameManager::Update(float deltaTime, ReactorManager *reactorManager) {
	if (gameOver) {
		return;
	}

	// Check win/loss conditions
	if (reactorManager->IsMeltdown() || reactorManager->IsKaboom()) {
		timerRunning = false;
		gameOver = true;
		return;
	}

	// Start timer when power exceeds threshold
	if (!timerRunning && reactorManager->GetTurbinePowerOut() > POWER_THRESHOLD) {
		timerRunning = true;
	}

	// Update timer if running
	if (timerRunning) {
		elapsedTime += deltaTime;
	}
}

float GameManager::GetElapsedTime() const {
	return elapsedTime;
}

bool GameManager::IsTimerRunning() const {
	return timerRunning;
}

bool GameManager::IsGameOver() const {
	return gameOver;
}

void GameManager::GetTimerFormatted(char *buffer, int bufferSize) const {
	int totalSeconds = static_cast<int>(elapsedTime);
	int minutes = totalSeconds / 60;
	int seconds = totalSeconds % 60;
	snprintf(buffer, bufferSize, "%02d:%02d", minutes, seconds);
}
