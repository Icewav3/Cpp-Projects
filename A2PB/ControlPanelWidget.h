#pragma once
#include <raylib.h>
#include <string>


struct WidgetPosition {
	float x, y;
	float width, height;
};

/// Creates a WidgetPosition structure with specified dimensions and position
/// @param x The x-coordinate of the widget
/// @param y The y-coordinate of the widget  
/// @param w The width of the widget
/// @param h The height of the widget
/// @return WidgetPosition structure with the specified values
inline WidgetPosition MakePosition(float x, float y, float w, float h) {
	return {x, y, w, h};
}


struct WidgetColors {
	Color active;
	Color inactive;
	Color text;
};

/// Creates a WidgetColors structure with specified color scheme
/// @param active Color used when the widget is active/on
/// @param inactive Color used when the widget is inactive/off
/// @param text Color used for text rendering
/// @return WidgetColors structure with the specified colors
inline WidgetColors MakeColors(Color active, Color inactive, Color text) {
	return {active, inactive, text};
}


class DisplayIndicator {
public:
	/// Constructor for a display indicator without blinking functionality
	/// @param position The position and size of the indicator
	/// @param colors The color scheme for the indicator
	/// @param isOn Initial state of the indicator (on/off)
	/// @param text Text to display on the indicator
	DisplayIndicator(WidgetPosition position, WidgetColors, bool isOn, std::string text);

	/// Constructor for a display indicator with optional blinking functionality
	/// @param position The position and size of the indicator
	/// @param colors The color scheme for the indicator
	/// @param isOn Initial state of the indicator (on/off)
	/// @param text Text to display on the indicator
	/// @param blinkInterval Interval in seconds for blinking (0 disables blinking)
	DisplayIndicator(WidgetPosition position, WidgetColors, bool isOn, std::string text, float blinkInterval = 0);

	/// Updates and renders the display indicator
	void Update();

	/// Sets the current state of the indicator
	/// @param value New state for the indicator (true for on, false for off)
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
	/// Constructor for a button widget
	/// @param position The position and size of the button
	/// @param colors The color scheme for the button
	/// @param isOn Initial state of the button
	/// @param isToggleable Whether the button toggles state or acts as momentary press
	Button(WidgetPosition position, WidgetColors colors, bool isOn, bool isToggleable = false);

	/// Updates the button state based on mouse input and renders it
	void Update();

	/// Gets the current state of the button
	/// @return Current button state (true for pressed/on, false for released/off)
	bool GetValue();

private:
	WidgetPosition position{};
	WidgetColors colors{};
	bool isOn;
	bool isToggleable;
};

class RadialDial {
public:
	/// Constructor for a radial dial widget
	/// @param position The position and size of the dial
	/// @param colors The color scheme for the dial
	/// @param value Initial value of the dial
	/// @param min Minimum value the dial can represent
	/// @param max Maximum value the dial can represent
	RadialDial(WidgetPosition position, WidgetColors colors, float value, float min, float max);

	/// Updates the dial state based on mouse input and renders it
	void Update();

	/// Sets the current value of the dial
	/// @param inputValue New value for the dial (clamped to min/max range)
	void SetValue(float inputValue);

	/// Gets the current value of the dial
	/// @return Current dial value
	float getValue();

private:
	WidgetPosition position{};
	WidgetColors colors{};
	float value;
	float min;
	float max;
};

class Slider {
public:
	/// Constructor for a horizontal slider widget
	/// @param position The position and size of the slider
	/// @param colors The color scheme for the slider
	/// @param value Initial value of the slider
	/// @param min Minimum value the slider can represent
	/// @param max Maximum value the slider can represent
	Slider(WidgetPosition position, WidgetColors colors, float value, float min, float max);

	/// Updates the slider state based on mouse input and renders it
	void Update();

	/// Gets the current value of the slider
	/// @return Current slider value
	float getValue();

private:
	WidgetPosition position{};
	WidgetColors colors{};
	float value;
	float min;
	float max;
};

