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
	//draw gauge outline
	float radius = length_ > height_ ? height_ : length_;
	DrawCircle(xpos_ + radius, ypos_ + radius, radius, BLACK);
	DrawCircle(xpos_ + radius, ypos_ + radius, radius*0.95f, WHITE);
	//draw needle
	auto drawStart = Vector2(0, 0);


	float percentage = (currentValue - minValue) / (maxValue - minValue);
 	//TODO MAGIC NUMBER BAD
	float needleLength = radius*0.9f;
	auto drawEnd = drawStart + Vector2(-needleLength,0.0f);
	//rotate matrix
	rlPushMatrix();
	rlTranslatef(this->xpos_ + radius,this->ypos_ + radius,0.0f);
	DrawText(label.c_str(), 0, radius*0.8, 4 , BLACK);
	rlRotatef(percentage * 180,0, 0,1); // twists camera

	// DrawLineEx(drawStart, drawEnd ,1, RED);
	DrawLineEx(drawStart, drawEnd ,3, RED);

	//TODO label

	rlPopMatrix();
}