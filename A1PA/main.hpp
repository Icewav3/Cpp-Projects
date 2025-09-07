#ifndef FIRST_TEST_H
#define FIRST_TEST_H

#include <iostream>
#include <string>

// Temperature conversion functions
float FahrenheitToCelsius(float fahrenheit);
float CelsiusToFahrenheit(float celsius);
float ChirpsToFahrenheit(float chirps);
bool IsValidTemperature(float fahrenheit);

// Password validation functions
bool hasLowerCase(const std::string& password);
bool hasUpperCase(const std::string& password);
bool hasNumber(const std::string& password);
std::string getPassword();

// Random number generation
int randomNumber(const int min, const int max);

#endif // FIRST_TEST_H
