#ifndef SLIDER_H
#define SLIDER_H

#include "Instrument.h"
#include <algorithm>
#include <string>

class Slider : public Instrument {
public:
	// Simplified constructor - auto-configures everything based on dimensions
	Slider(float x, float y, float width, float height,
	       float min_value = 0.0f, float max_value = 100.0f,
	       float initial_value = 0.0f, const std::string &label = "");

	void Update(float delta_time) override;

	// Simple getters/setters
	float GetValue() const { return current_value_; }

	void SetValue(float value);

	void SetRange(float min_val, float max_val);

	void SetLabel(const std::string &label) { label_ = label; }

	// Auto-styling based on size
	void SetTheme(Color primary_color);

protected:
	void Draw() override;

private:
	void HandleInput();

	void AutoConfigureLayout();

	Vector2 GetHandlePosition() const;

	Rectangle GetTrackBounds() const;

	Rectangle GetHandleBounds() const;

	float CalculateValueFromMouse(Vector2 mouse_pos) const;

	// Core values
	float min_value_;
	float max_value_;
	float current_value_;
	std::string label_;

	// Auto-configured layout
	bool is_horizontal_;
	float track_thickness_;
	float handle_size_;
	Rectangle track_rect_;
	Vector2 label_position_;

	// Colors (auto-themed)
	Color track_color_;
	Color handle_color_;
	Color active_color_;
	Color text_color_;

	// Input state
	bool is_dragging_;
	bool is_hovered_;

	// Auto-calculated spacing
	float label_spacing_;
	float value_spacing_;
};

#endif // SLIDER_H
