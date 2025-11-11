#include "Slider.h"

Slider::Slider(
	float xpos,
	float ypos,
	float length,
	float width,
	float minValue,
	float maxValue,
	float initialValue,
	const std::string &label,
	float handleSize,
	float trackThickness,
	bool showMinMaxLabels,
	Color trackColor,
	Color handleColor,
	Color textColor)
	: Instrument(xpos, ypos, length, width),
	  minValue_(minValue),
	  maxValue_(maxValue),
	  currentValue_(std::clamp(initialValue, minValue, maxValue)),
	  label_(label),
	  showMinMaxLabels_(showMinMaxLabels),
	  handleSize_(handleSize),
	  trackThickness_(trackThickness),
	  trackColor_(trackColor),
	  handleColor_(handleColor),
	  textColor_(textColor),
	  isDragging_(false),
	  isHovered_(false),
	  dragOffset_({0, 0}) {
	// Determine orientation based on dimensions
	isHorizontal_ = length_ > width_;
}

void Slider::Update(float DeltaTime) {
	if (!IsBroken) {
		HandleInput();
	}
	Draw();
}

void Slider::HandleInput() {
	Vector2 mousePos = GetMousePosition();
	Rectangle handleBounds = GetHandleBounds();

	// Check if mouse is over handle
	isHovered_ = CheckCollisionPointRec(mousePos, handleBounds);

	// Start dragging
	if (isHovered_ && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
		isDragging_ = true;
		Vector2 handleCenter = GetHandlePosition();
		dragOffset_ = {mousePos.x - handleCenter.x, mousePos.y - handleCenter.y};
	}

	// Stop dragging
	if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
		isDragging_ = false;
	}

	// Handle dragging
	if (isDragging_) {
		float newValue = CalculateValueFromPosition(mousePos);
		currentValue_ = std::clamp(newValue, minValue_, maxValue_);
	}
}

void Slider::Draw() {
	Rectangle trackBounds = GetTrackBounds();
	Rectangle handleBounds = GetHandleBounds();

	// Draw track
	DrawRectangleRec(trackBounds, trackColor_);
	DrawRectangleLinesEx(trackBounds, 1.0f, BLACK);

	// Draw handle
	Color handleDrawColor = isDragging_ ? YELLOW : (isHovered_ ? LIGHTGRAY : handleColor_);
	DrawRectangleRec(handleBounds, handleDrawColor);
	DrawRectangleLinesEx(handleBounds, 2.0f, BLACK);

	// Draw label if provided
	if (!label_.empty()) {
		const char *labelText = label_.c_str();
		int textWidth = MeasureText(labelText, fontSize_);

		if (isHorizontal_) {
			// Label above horizontal slider
			DrawText(labelText,
			         xpos_ + (length_ - textWidth) / 2,
			         ypos_ - fontSize_ - labelSpacing_,
			         fontSize_, textColor_);
		} else {
			// Label above vertical slider
			DrawText(labelText,
			         xpos_ + (width_ - textWidth) / 2,
			         ypos_ - fontSize_ - labelSpacing_,
			         fontSize_, textColor_);
		}
	}

	// Draw min/max labels if enabled
	if (showMinMaxLabels_) {
		char minText[32], maxText[32];
		snprintf(minText, sizeof(minText), "%.1f", minValue_);
		snprintf(maxText, sizeof(maxText), "%.1f", maxValue_);

		if (isHorizontal_) {
			// Min on left, max on right
			DrawText(minText, xpos_ - MeasureText(minText, fontSize_) - minMaxSpacing_,
			         ypos_ + (width_ - fontSize_) / 2, fontSize_, textColor_);
			DrawText(maxText, xpos_ + length_ + minMaxSpacing_,
			         ypos_ + (width_ - fontSize_) / 2, fontSize_, textColor_);
		} else {
			// Min at bottom, max at top
			int minWidth = MeasureText(minText, fontSize_);
			int maxWidth = MeasureText(maxText, fontSize_);
			DrawText(maxText, xpos_ + (width_ - maxWidth) / 2,
			         ypos_ - fontSize_ - minMaxSpacing_, fontSize_, textColor_);
			DrawText(minText, xpos_ + (width_ - minWidth) / 2,
			         ypos_ + length_ + minMaxSpacing_, fontSize_, textColor_);
		}
	}

	// Draw current value near handle
	char valueText[32];
	snprintf(valueText, sizeof(valueText), "%.1f", currentValue_);
	int valueWidth = MeasureText(valueText, fontSize_);

	Vector2 handlePos = GetHandlePosition();
	if (isHorizontal_) {
		DrawText(valueText, handlePos.x - valueWidth / 2,
		         ypos_ + width_ + minMaxSpacing_, fontSize_, textColor_);
	} else {
		DrawText(valueText, xpos_ + width_ + minMaxSpacing_,
		         handlePos.y - fontSize_ / 2, fontSize_, textColor_);
	}
}

Rectangle Slider::GetTrackBounds() const {
	if (isHorizontal_) {
		float trackY = ypos_ + (width_ - trackThickness_) / 2;
		return {xpos_, trackY, length_, trackThickness_};
	} else {
		float trackX = xpos_ + (width_ - trackThickness_) / 2;
		return {trackX, ypos_, trackThickness_, length_};
	}
}

Rectangle Slider::GetHandleBounds() const {
	Vector2 handlePos = GetHandlePosition();

	if (isHorizontal_) {
		return {
			handlePos.x - handleSize_ / 2,
			handlePos.y - handleSize_ / 2,
			handleSize_,
			handleSize_
		};
	} else {
		return {
			handlePos.x - handleSize_ / 2,
			handlePos.y - handleSize_ / 2,
			handleSize_,
			handleSize_
		};
	}
}

Vector2 Slider::GetHandlePosition() const {
	float position = MapValueToPosition(currentValue_);

	if (isHorizontal_) {
		return {xpos_ + position, ypos_ + width_ / 2};
	} else {
		// Vertical: position from bottom to top (inverted for intuitive control)
		return {xpos_ + width_ / 2, ypos_ + length_ - position};
	}
}

float Slider::MapValueToPosition(float value) const {
	float normalizedValue = (value - minValue_) / (maxValue_ - minValue_);
	normalizedValue = std::clamp(normalizedValue, 0.0f, 1.0f);

	if (isHorizontal_) {
		return normalizedValue * length_;
	} else {
		return normalizedValue * length_;
	}
}

float Slider::MapPositionToValue(float position) const {
	float normalizedPosition = position / (isHorizontal_ ? length_ : length_);
	normalizedPosition = std::clamp(normalizedPosition, 0.0f, 1.0f);
	return minValue_ + normalizedPosition * (maxValue_ - minValue_);
}

float Slider::CalculateValueFromPosition(Vector2 mousePos) const {
	if (isHorizontal_) {
		float relativePos = mousePos.x - xpos_;
		return MapPositionToValue(relativePos);
	} else {
		// Vertical: inverted so dragging up increases value
		float relativePos = (ypos_ + length_) - mousePos.y;
		return MapPositionToValue(relativePos);
	}
}

bool Slider::IsPointOnHandle(Vector2 point) const {
	return CheckCollisionPointRec(point, GetHandleBounds());
}

// Setters
void Slider::SetValue(float value) {
	currentValue_ = std::clamp(value, minValue_, maxValue_);
}

void Slider::SetMinMaxValues(float min, float max) {
	minValue_ = min;
	maxValue_ = max;
	currentValue_ = std::clamp(currentValue_, minValue_, maxValue_);
}

void Slider::SetLabel(const std::string &label) {
	label_ = label;
}

void Slider::SetColors(Color track, Color handle, Color text) {
	trackColor_ = track;
	handleColor_ = handle;
	textColor_ = text;
}

// Getters
float Slider::GetCurrentValue() const {
	return currentValue_;
}

float Slider::GetMinValue() const {
	return minValue_;
}

float Slider::GetMaxValue() const {
	return maxValue_;
}

bool Slider::IsHorizontal() const {
	return isHorizontal_;
}

bool Slider::IsBeingDragged() const {
	return isDragging_;
}
