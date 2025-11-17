#ifndef CPP_PROJECTS_INSTRUMENT_H
#define CPP_PROJECTS_INSTRUMENT_H

#include "raylib.h"
#include <string>

class Instrument {
public:
	virtual ~Instrument() = default;

	// Simplified constructor - just position and size
	Instrument(float x, float y, float width, float height)
		: position_{x, y},
		  size_{width, height},
		  bounds_{x, y, width, height} {
	}

	// Main update method - handles both logic and rendering
	virtual void Update(float delta_time) = 0;

	// Getters for common properties
	Vector2 GetPosition() const { return position_; }
	Vector2 GetSize() const { return size_; }
	Rectangle GetBounds() const { return bounds_; }

	// Setters
	void SetPosition(float x, float y) {
		position_ = {x, y};
		bounds_.x = x;
		bounds_.y = y;
	}

protected:
	virtual void Draw() = 0;

	Vector2 position_;
	Vector2 size_;
	Rectangle bounds_;

	static constexpr Color kVintageBeige = {240, 230, 200, 255}; // Sun-bleached beige
	static constexpr Color kVintageBrown = {139, 120, 93, 255}; // Faded brown
	static constexpr Color kVintageGreen = {85, 107, 47, 255}; // Military olive green
	static constexpr Color kVintageRed = {139, 69, 19, 255}; // Rust red
	static constexpr Color kVintageYellow = {218, 165, 32, 255}; // Aged gold/yellow
	static constexpr Color kVintageBlack = {47, 47, 47, 255}; // Aged black
	static constexpr Color kVintageWhite = {250, 245, 235, 255}; // Off-white/cream
	static constexpr Color kVintageOrange = {205, 133, 63, 255}; // Faded orange

	// Common styling constants - vintage nuclear control panel theme
	static constexpr Color kDefaultTextColor = kVintageBlack;
	static constexpr Color kDefaultBackgroundColor = kVintageBeige;
	static constexpr Color kDefaultBorderColor = kVintageBrown;
	static constexpr int kDefaultFontSize = 12;
	static constexpr float kDefaultPadding = 5.0f;
};

#endif //CPP_PROJECTS_INSTRUMENT_H
