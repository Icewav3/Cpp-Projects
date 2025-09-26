#pragma once
#include <raylib.h>
#include <string>


struct WidgetPosition {
	float x, y;
	float width, height;
};

inline WidgetPosition MakePosition(float x, float y, float w, float h) {
	return {x, y, w, h};
}


struct WidgetColors {
	Color active;
	Color inactive;
	Color text;
};

inline WidgetColors MakeColors(Color active, Color inactive, Color text) {
	return {active, inactive, text};
}


class DisplayIndicator {
public:
	DisplayIndicator(WidgetPosition position, WidgetColors, bool isOn, std::string text);

	DisplayIndicator(WidgetPosition position, WidgetColors, bool isOn, std::string text, float blinkInterval = 0);

	void Update();

	void SetValue(bool value);

private:
	WidgetPosition position{};
	WidgetColors colors{};
	bool isOn;
	std::string text;
	float blinkInterval;
};

class Button {
public:
	Button(WidgetPosition position, WidgetColors colors, bool isOn, bool isToggleable = false);

	void Update();

	bool GetValue();

private:
	WidgetPosition position{};
	WidgetColors colors{};
	bool isOn;
	bool isToggleable;
};

class RadialDial {
public:
	RadialDial(WidgetPosition position, WidgetColors, int value, int min, int max);

	void Update();

	void SetValue(float value);

private:
	WidgetPosition position{};
	WidgetColors colors{};
	int value;
	int min;
	int max;
};

class Slider {
public:
	Slider(WidgetPosition position, WidgetColors, float value, float min, float max);

	void Update();

	float getValue();

private:
	WidgetPosition position{};
	WidgetColors colors{};
	float value;
	float min;
	float max;
};

