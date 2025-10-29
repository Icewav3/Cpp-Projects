#ifndef CPP_PROJECTS_DIAL_H
#define CPP_PROJECTS_DIAL_H

#include "Instrument.h"
#include <string>
#include "raylib.h"

//TODO
class Dial : public Instrument {
public:
	Dial(
		float xpos,
		float ypos,
		float length,
		float width,
		float min,
		float max,
		float value,
		const std::string &label = "");

	void Update(float DeltaTime) override;

	void SetTargetValue(float value);

	void SetLabel(const std::string &label);

private:
	void Draw() override;

	float minValue;
	float maxValue;
	float currentValue; // Actual needle position

	std::string label;

	// Visual parameters (270 deg)
	const float needleSpeed = 120.0f; // Degrees per second
	const float dialStartAngle = 225.0f; // Bottom-left
	const float dialEndAngle = -45.0f; // Bottom-right

	// Broken dial behavior
	float brokenTarget;
	const float brokenChangeInterval = 0.3f;
};

#endif //CPP_PROJECTS_DIAL_H
