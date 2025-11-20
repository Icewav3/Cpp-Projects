#ifndef CPP_PROJECTS_DIAL_H
#define CPP_PROJECTS_DIAL_H

#include "Instrument.h"
#include <string>
#include "raylib.h"

class Dial : public Instrument {
public:
	Dial(
		float xpos,
		float ypos,
		float length,
		float height,
		float min,
		float max,
		float value,
		const std::string &label = "");

	void Update(float DeltaTime) override;

	void SetValue(float value);

	void SetLabel(const std::string &label);

private:
	void Draw() override;

	float minValue;
	float maxValue;
	float currentValue; // Actual needle position

	std::string label;

	// Visual parameters (270 deg)
	const float dialStartAngle = -225.0f; // Bottom-left
	const float dialEndAngle = 45.0f; // Bottom-right
};

#endif //CPP_PROJECTS_DIAL_H
