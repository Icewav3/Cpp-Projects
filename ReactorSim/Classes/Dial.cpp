#include "Dial.h"


//TODO
Dial::Dial(
	float xpos,
	float ypos,
	float length,
	float width,
	float min,
	float max,
	float value,
	const std::string &label)
	: Instrument(xpos, ypos, length, width),
	  minValue(min),
	  maxValue(max),
	  currentValue(value),
	  label(label) {
}

void Dial::Update(float DeltaTime) {
	Draw();
}

void Dial::Draw() {
}
