#pragma once
#include "ControlPanelWidget.h"

#include <string>
#include <cmath>

#include "../A1PB/Utility.hpp"

//Display Indicator class
DisplayIndicator::DisplayIndicator(WidgetPosition position, WidgetColors colors, bool isOn, std::string text) {
	this->isOn = isOn;
	this->position = position;
	this->colors = colors;
	this->text = text;
	this->blinkInterval = 0;
}

DisplayIndicator::DisplayIndicator(WidgetPosition position, WidgetColors colors, bool isOn, std::string text,
                                   float blinkInterval) {
	this->isOn = isOn;
	this->position = position;
	this->colors = colors;
	this->text = text;
	this->blinkInterval = blinkInterval;
}

void DisplayIndicator::Update() {
	Color currentColor;
	if (blinkInterval != 0 && isOn) {
		// Use GetTime() to create a blinking effect
		double currentTime = GetTime();
		bool shouldBlink = ((int) (currentTime / blinkInterval) % 2) == 0;
		currentColor = shouldBlink ? colors.active : colors.inactive;
	} else {
		currentColor = isOn ? colors.active : colors.inactive;
	}

	DrawRectangle((int) position.x, (int) position.y, (int) position.width, (int) position.height, currentColor);
	DrawRectangleLines((int) position.x, (int) position.y, (int) position.width, (int) position.height, BLACK);
	// Draw text if it exists
	if (!text.empty()) {
		int fontSize = 20;
		int textWidth = MeasureText(text.c_str(), fontSize);
		int textX = (int) (position.x + (position.width - textWidth) / 2);
		int textY = (int) (position.y + (position.height - fontSize) / 2);
		DrawText(text.c_str(), textX, textY, fontSize, colors.text);
	}
}

void DisplayIndicator::SetValue(bool value) {
	isOn = value;
}

//Button class

Button::Button(WidgetPosition position, WidgetColors colors, bool isOn, bool isToggleable) {
	this->isOn = isOn;
	this->position = position;
	this->colors = colors;
	this->isToggleable = isToggleable;
}

void Button::Update() {
	Vector2 mousePos = GetMousePosition();
	bool mouseClicked = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
	bool mouseDown = IsMouseButtonDown(MOUSE_BUTTON_LEFT);

	// Check if mouse is inside button
	Rectangle buttonRect = {position.x, position.y, position.width, position.height};
	bool mouseInside = CheckCollisionPointRec(mousePos, buttonRect);

	if (isToggleable) {
		// Toggle
		if (mouseInside && mouseClicked) {
			isOn = !isOn;
		}
	} else {
		// Press
		if (mouseInside && mouseDown) {
			isOn = true;
		} else {
			isOn = false;
		}
	}

	// Draw
	Color currentColor = isOn ? colors.active : colors.inactive;
	DrawRectangle((int) position.x, (int) position.y, (int) position.width, (int) position.height, currentColor);
	DrawRectangleLines((int) position.x, (int) position.y, (int) position.width, (int) position.height, BLACK);
}

bool Button::GetValue() {
	return isOn;
}

RadialDial::RadialDial(WidgetPosition position, WidgetColors colors, float value, float min, float max) {
	this->position = position;
	this->value = value;
	this->min = min;
	this->max = max;
	this->colors = colors;
	this->value = value;
}

void RadialDial::Update() {
	Vector2 mousePos = GetMousePosition();
	bool mouseDown = IsMouseButtonDown(MOUSE_BUTTON_LEFT);

	float centerX = position.x + position.width / 2;
	float centerY = position.y + position.height / 2;
	float radius = std::min(position.width, position.height) / 2 - 5;

	// Check if mouse is inside dial area
	float distanceFromCenter = std::sqrt(std::pow(mousePos.x - centerX, 2) + std::pow(mousePos.y - centerY, 2));
	bool mouseInside = distanceFromCenter <= radius;

	if (mouseInside && mouseDown) {
		// Calculate angle from mouse position
		float angle = atan2(mousePos.y - centerY, mousePos.x - centerX);
		// Convert angle to value (0 to max range, starting from top)
		angle = angle + PI / 2; // Adjust so 0 degrees is at top
		if (angle < 0) angle += 2 * PI;
		float relativeAngle = angle / (2 * PI);
		value = min + relativeAngle * (max - min);
		value = clamp(value, min, max);
	}

	// Draw dial background
	DrawCircle(centerX, centerY, radius, colors.inactive);
	DrawCircleLines(centerX, centerY, radius, BLACK);

	// Draw dial
	float valueAngle = ((value - min) / (max - min)) * 2 * PI - PI / 2; // Start from top
	float indicatorX = centerX + cos(valueAngle) * (radius - 10);
	float indicatorY = centerY + sin(valueAngle) * (radius - 10);
	DrawLine(centerX, centerY, indicatorX, indicatorY, colors.active);
	DrawCircle(indicatorX, indicatorY, 5, colors.active);

	// Draw dot
	DrawCircle(centerX, centerY, 3, BLACK);
}

void RadialDial::SetValue(float inputValue) {
	value = clamp(inputValue, min, max);
}

float RadialDial::getValue() {
	return value;
}

Slider::Slider(WidgetPosition position, WidgetColors colors, float value, float min, float max) {
	this->position = position;
	this->value = value;
	this->min = min;
	this->max = max;
	this->colors = colors;
	this->value = value;
}

void Slider::Update() {
	Vector2 mousePos = GetMousePosition();
	bool mouseDown = IsMouseButtonDown(MOUSE_BUTTON_LEFT);

	// Check if mouse is inside slider bounds
	Rectangle sliderRect = {position.x, position.y, position.width, position.height};
	bool mouseInside = CheckCollisionPointRec(mousePos, sliderRect);

	if (mouseInside && mouseDown) {
		// Calculate value based on mouse position
		float relativePos = (mousePos.x - position.x) / position.width;
		relativePos = clamp(relativePos, 0.0f, 1.0f);
		value = min + relativePos * (max - min);
	}

	// Draw background
	DrawRectangle((int) position.x, (int) position.y, (int) position.width, (int) position.height, colors.inactive);
	DrawRectangleLines((int) position.x, (int) position.y, (int) position.width, (int) position.height, BLACK);

	// Draw handle
	float handlePos = (value - min) / (max - min) * position.width;
	float handleWidth = 10;
	DrawRectangle((int) (position.x + handlePos - handleWidth / 2), (int) position.y, (int) handleWidth,
	              (int) position.height, colors.active);
}

float Slider::getValue() {
	return value;
}
