#include "Dial.h"

#include <iostream>
#include <raymath.h>
#include <rlgl.h>

Dial::Dial(
	float xpos,
	float ypos,
	float length,
	float height,
	float min,
	float max,
	float value,
	const std::string &label)
	: Instrument(xpos, ypos, length, height),
	  minValue(min),
	  maxValue(max),
	  currentValue(value),
	  label(label) {
}

void Dial::Update(float DeltaTime) {
	Draw();
}

void Dial::Draw() {
	// Draw gauge outline
	float radius = size_.x > size_.y ? size_.y * 0.5f : size_.x * 0.5f;
	Vector2 center = {position_.x + radius, position_.y + radius};

	DrawCircle(center.x, center.y, radius, BLACK);
	DrawCircle(center.x, center.y, radius * 0.95f, WHITE);

	// Draw needle
	auto drawStart = Vector2(0, 0);

	float percentage = (currentValue - minValue) / (maxValue - minValue);
	float needleLength = radius * 0.9f;
	auto drawEnd = drawStart + Vector2(-needleLength, 0.0f);

	// Rotate matrix
	rlPushMatrix();
	rlTranslatef(center.x, center.y, 0.0f);
	DrawText(label.c_str(), 0, radius * 0.8f, 4, BLACK);
	rlRotatef(percentage * 180, 0, 0, 1); // twists camera

	DrawLineEx(drawStart, drawEnd, 3, RED);

	rlPopMatrix();
}

void Dial::SetTargetValue(float value) {
	currentValue = value;
}

void Dial::SetLabel(const std::string &label) {
	this->label = label;
}
