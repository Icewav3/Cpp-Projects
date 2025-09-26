#pragma once
#include "ControlPanelWidget.h"

#include <string>

#include "../A1PB/Utility.hpp"

//Display Indicator class
DisplayIndicator::DisplayIndicator(WidgetPosition position, WidgetColors colors, bool isOn, std::string text) {
	this->isOn = isOn;
	this->position = position;
	this->colors = colors;
	this->text = text;
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
		Color currentColor = isOn ? colors.active : colors.inactive;
	}

	DrawRectangle(position.x, position.y, position.width, position.height, currentColor);
	DrawRectangleLines(position.x, position.y, position.width, position.height, BLACK);
	// Draw text if it exists
	if (!text.empty()) {
		int fontSize = 20;
		int textWidth = MeasureText(text.c_str(), fontSize);
		float textX = position.x + (position.width - textWidth) / 2;
		float textY = position.y + (position.height - fontSize) / 2;
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

	// Check if mouse is inside button bounds
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
	DrawRectangle(position.x, position.y, position.width, position.height, currentColor);
	DrawRectangleLines(position.x, position.y, position.width, position.height, BLACK);
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
}

void RadialDial::SetValue(float inputValue) {
	value = clamp(inputValue, min, max);
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
}

float Slider::getValue() {
}
