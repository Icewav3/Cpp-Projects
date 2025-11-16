#ifndef CPP_PROJECTS_INSTRUMENT_H
#define CPP_PROJECTS_INSTRUMENT_H

#include "raylib.h"
#include <string>

class Instrument {
public:
	virtual ~Instrument() = default;

	// Simplified constructor - just position and size
	Instrument(float x, float y, float width, float height)
		: is_broken_(false),
		  position_{x, y},
		  size_{width, height},
		  bounds_{x, y, width, height} {
	}

	// Main update method - handles both logic and rendering
	virtual void Update(float delta_time) = 0;

	// Getters for common properties
	Vector2 GetPosition() const { return position_; }
	Vector2 GetSize() const { return size_; }
	Rectangle GetBounds() const { return bounds_; }
	bool IsBroken() const { return is_broken_; }

	// Setters
	void SetPosition(float x, float y) {
		position_ = {x, y};
		bounds_.x = x;
		bounds_.y = y;
	}

	void SetBroken(bool broken) { is_broken_ = broken; }

protected:
	virtual void Draw() = 0;

	bool is_broken_;
	Vector2 position_;
	Vector2 size_;
	Rectangle bounds_;

	// Common styling constants
	static constexpr Color kDefaultTextColor = BLACK;
	static constexpr Color kDefaultBackgroundColor = WHITE;
	static constexpr Color kDefaultBorderColor = BLACK;
	static constexpr int kDefaultFontSize = 12;
	static constexpr float kDefaultPadding = 5.0f;
};

#endif //CPP_PROJECTS_INSTRUMENT_H
