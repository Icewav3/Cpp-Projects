#include "Slider.h"
#include <cmath>

Slider::Slider(float x, float y, float width, float height,
               float min_value, float max_value, float initial_value,
               const std::string &label)
	: Instrument(x, y, width, height),
	  min_value_(min_value),
	  max_value_(max_value),
	  current_value_(std::clamp(initial_value, min_value, max_value)),
	  label_(label),
	  is_dragging_(false),
	  is_hovered_(false) {
	AutoConfigureLayout();
	SetTheme(BLUE); // Default theme
}

void Slider::AutoConfigureLayout() {
	// Determine orientation based on aspect ratio
	is_horizontal_ = size_.x > size_.y;

	// Auto-scale dimensions based on size
	float min_dimension = std::min(size_.x, size_.y);

	// Auto-configure track and handle sizes
	if (is_horizontal_) {
		track_thickness_ = std::max(4.0f, min_dimension * 0.2f);
		handle_size_ = std::max(12.0f, min_dimension * 0.8f);
	} else {
		track_thickness_ = std::max(4.0f, min_dimension * 0.2f);
		handle_size_ = std::max(12.0f, min_dimension * 0.8f);
	}

	// Auto-calculate spacing
	label_spacing_ = kDefaultPadding;
	value_spacing_ = kDefaultPadding;

	// Configure track rectangle
	if (is_horizontal_) {
		float track_y = position_.y + (size_.y - track_thickness_) * 0.5f;
		track_rect_ = {position_.x, track_y, size_.x, track_thickness_};
	} else {
		float track_x = position_.x + (size_.x - track_thickness_) * 0.5f;
		track_rect_ = {track_x, position_.y, track_thickness_, size_.y};
	}

	// Auto-position label
	if (!label_.empty()) {
		int text_width = MeasureText(label_.c_str(), kDefaultFontSize);
		if (is_horizontal_) {
			label_position_ = {
				position_.x + (size_.x - text_width) * 0.5f,
				position_.y - kDefaultFontSize - label_spacing_
			};
		} else {
			label_position_ = {
				position_.x + (size_.x - text_width) * 0.5f,
				position_.y - kDefaultFontSize - label_spacing_
			};
		}
	}
}

void Slider::SetTheme(Color primary_color) {
	track_color_ = Fade(primary_color, 0.3f);
	handle_color_ = primary_color;
	active_color_ = ColorBrightness(primary_color, 0.2f);
	text_color_ = kDefaultTextColor;
}

void Slider::Update(float delta_time) {
	if (!is_broken_) {
		HandleInput();
	}
	Draw();
}

void Slider::HandleInput() {
	Vector2 mouse_pos = GetMousePosition();
	Rectangle handle_bounds = GetHandleBounds();

	// Check hover state
	is_hovered_ = CheckCollisionPointRec(mouse_pos, handle_bounds);

	// Handle mouse interaction
	if (is_hovered_ && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
		is_dragging_ = true;
	}

	if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
		is_dragging_ = false;
	}

	// Update value while dragging
	if (is_dragging_) {
		float new_value = CalculateValueFromMouse(mouse_pos);
		SetValue(new_value);
	}
}

void Slider::Draw() {
	// Draw track
	DrawRectangleRounded(track_rect_, 0.5f, 8, track_color_);
	DrawRectangleRoundedLines(track_rect_, 0.5f, 8, kDefaultBorderColor);

	// Draw handle with smooth color transitions
	Rectangle handle_bounds = GetHandleBounds();
	Color handle_draw_color = is_dragging_
		                          ? active_color_
		                          : (is_hovered_ ? ColorBrightness(handle_color_, 0.1f) : handle_color_);

	DrawRectangleRounded(handle_bounds, 0.3f, 8, handle_draw_color);
	DrawRectangleRoundedLines(handle_bounds, 0.3f, 8, kDefaultBorderColor);

	// Draw label if present
	if (!label_.empty()) {
		DrawText(label_.c_str(),
		         (int) label_position_.x, (int) label_position_.y,
		         kDefaultFontSize, text_color_);
	}

	// Auto-draw current value
	char value_text[32];
	snprintf(value_text, sizeof(value_text), "%.1f", current_value_);
	int value_width = MeasureText(value_text, kDefaultFontSize - 2);

	Vector2 handle_pos = GetHandlePosition();
	Vector2 value_pos;

	if (is_horizontal_) {
		value_pos = {
			handle_pos.x - value_width * 0.5f,
			position_.y + size_.y + value_spacing_
		};
	} else {
		value_pos = {
			position_.x + size_.x + value_spacing_,
			handle_pos.y - (kDefaultFontSize - 2) * 0.5f
		};
	}

	DrawText(value_text, (int) value_pos.x, (int) value_pos.y,
	         kDefaultFontSize - 2, text_color_);
}

Vector2 Slider::GetHandlePosition() const {
	float normalized_value = (current_value_ - min_value_) / (max_value_ - min_value_);
	normalized_value = std::clamp(normalized_value, 0.0f, 1.0f);

	if (is_horizontal_) {
		float handle_x = position_.x + normalized_value * size_.x;
		return {handle_x, position_.y + size_.y * 0.5f};
	} else {
		float handle_y = position_.y + size_.y - (normalized_value * size_.y);
		return {position_.x + size_.x * 0.5f, handle_y};
	}
}

Rectangle Slider::GetHandleBounds() const {
	Vector2 handle_pos = GetHandlePosition();
	return {
		handle_pos.x - handle_size_ * 0.5f,
		handle_pos.y - handle_size_ * 0.5f,
		handle_size_,
		handle_size_
	};
}

Rectangle Slider::GetTrackBounds() const {
	return track_rect_;
}

float Slider::CalculateValueFromMouse(Vector2 mouse_pos) const {
	float normalized_pos;

	if (is_horizontal_) {
		float relative_x = mouse_pos.x - position_.x;
		normalized_pos = relative_x / size_.x;
	} else {
		float relative_y = mouse_pos.y - position_.y;
		normalized_pos = 1.0f - (relative_y / size_.y); // Inverted for intuitive control
	}

	normalized_pos = std::clamp(normalized_pos, 0.0f, 1.0f);
	return min_value_ + normalized_pos * (max_value_ - min_value_);
}

void Slider::SetValue(float value) {
	current_value_ = std::clamp(value, min_value_, max_value_);
}

void Slider::SetRange(float min_val, float max_val) {
	min_value_ = min_val;
	max_value_ = max_val;
    current_value_ = std::clamp(current_value_, min_value_, max_value_);
}