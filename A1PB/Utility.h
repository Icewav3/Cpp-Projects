#pragma once
template <typename T>
bool inRangeInclusive(const T& value, const T& min, const T& max) {
	return value >= min && value <= max;
}
template <typename T>
T clamp(const T& value, const T& min, const T& max) {
	return value < min ? min : value > max ? max : value;
}