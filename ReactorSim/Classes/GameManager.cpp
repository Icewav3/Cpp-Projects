#include "GameManager.h"
#include "Reactor/ReactorManager.h"
#include <cstdio>
#include <algorithm>

GameManager::GameManager()
	: currentScene(GameScene::MAIN_MENU)
	  , elapsedTime(0.0f)
	  , timerRunning(false)
	  , totalPowerAccumulated(0.0f)
	  , powerSampleCount(0) {
}

void GameManager::Update(float deltaTime, ReactorManager *reactorManager) {
	if (currentScene != GameScene::PLAYING) {
		return;
	}

	// Update statistics
	UpdateStatistics(reactorManager, deltaTime);

	// Check win/loss conditions
	if (reactorManager->IsMeltdown() || reactorManager->IsKaboom()) {
		timerRunning = false;
		FinalizeStatistics(reactorManager);
		currentScene = GameScene::END_SCREEN;
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

void GameManager::UpdateStatistics(ReactorManager *reactorManager, float deltaTime) {
	// Track highest values
	stats.highestTemp = std::max(stats.highestTemp, reactorManager->GetReactorTemp());
	stats.highestPressure = std::max(stats.highestPressure, reactorManager->GetReactorPressure());

	// Accumulate power for average calculation
	float currentPower = reactorManager->GetTurbinePowerOut();
	totalPowerAccumulated += currentPower;
	powerSampleCount++;
}

void GameManager::FinalizeStatistics(ReactorManager *reactorManager) {
	stats.totalTime = elapsedTime;
	stats.revenue = reactorManager->GetRevenue();

	// Calculate average power
	if (powerSampleCount > 0) {
		stats.averagePowerOutput = totalPowerAccumulated / powerSampleCount;
	}

	// Determine failure type
	if (reactorManager->IsMeltdown()) {
		stats.failureType = FailureType::MELTDOWN;
	} else if (reactorManager->IsKaboom()) {
		stats.failureType = FailureType::OVERPRESSURE;
	}
}

void GameManager::Reset() {
	elapsedTime = 0.0f;
	timerRunning = false;
	totalPowerAccumulated = 0.0f;
	powerSampleCount = 0;
	stats = GameStatistics();
	currentScene = GameScene::MAIN_MENU;
}

GameScene GameManager::GetCurrentScene() const {
	return currentScene;
}

void GameManager::SetScene(GameScene scene) {
	currentScene = scene;
}

float GameManager::GetElapsedTime() const {
	return elapsedTime;
}

bool GameManager::IsTimerRunning() const {
	return timerRunning;
}

void GameManager::GetTimerFormatted(char *buffer, int bufferSize) const {
	int totalSeconds = static_cast<int>(elapsedTime);
	int minutes = totalSeconds / 60;
	int seconds = totalSeconds % 60;
	snprintf(buffer, bufferSize, "%02d:%02d", minutes, seconds);
}

const GameStatistics &GameManager::GetStatistics() const {
	return stats;
}
