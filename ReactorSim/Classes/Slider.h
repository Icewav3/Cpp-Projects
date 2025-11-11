#ifndef SLIDER_H
#define SLIDER_H

#include "Instrument.h"
#include <algorithm>
#include <cmath>
#include <raylib.h>
#include <string>

class Slider : public Instrument {
public:
	Slider(
		float xpos,
		float ypos,
		float length,
		float width,
		float minValue,
		float maxValue,
		float initialValue = 0.0f,
		const std::string &label = "",
		float handleSize = 12.0f,
		float trackThickness = 6.0f,
		bool showMinMaxLabels = true,
		Color trackColor = GRAY,
		Color handleColor = WHITE,
		Color textColor = BLACK);

	void Update(float DeltaTime) override;

	void SetValue(float value);

	void SetMinMaxValues(float min, float max);

	void SetLabel(const std::string &label);

	void SetColors(Color track, Color handle, Color text);

	float GetCurrentValue() const;

	float GetMinValue() const;

	float GetMaxValue() const;

	bool IsHorizontal() const;

	bool IsBeingDragged() const;

private:
	void Draw() override;

	// Input handling
	void HandleInput();

	bool IsPointOnHandle(Vector2 point) const;

	float CalculateValueFromPosition(Vector2 mousePos) const;

	Vector2 GetHandlePosition() const;

	Rectangle GetTrackBounds() const;

	Rectangle GetHandleBounds() const;

	// Value mapping
	float MapValueToPosition(float value) const;

	float MapPositionToValue(float position) const;

	// Member variables
	float minValue_;
	float maxValue_;
	float currentValue_;

	std::string label_;
	bool showMinMaxLabels_;

	// Visual configuration
	float handleSize_;
	float trackThickness_;
	Color trackColor_;
	Color handleColor_;
	Color textColor_;

	// Interaction state
	bool isDragging_;
	bool isHovered_;
	Vector2 dragOffset_;

	// Cached orientation (determined from length vs width)
	bool isHorizontal_;

	// Text sizing
	const int fontSize_ = 12;
	const float labelSpacing_ = 5.0f;
	const float minMaxSpacing_ = 3.0f;
	// Broken slider behavior will be implemented later
};
#endif // SLIDER_H
