#include <iostream>
#include <limits>
// Functions
float FahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32.0f) * 5.0f / 9.0f;
}
float CelsiusToFahrenheit(float celsius)
{
    return celsius * (9.0f / 5.0f) + 32.0f;
}
float ChirpsToFahrenheit(float chirps)
{
    return chirps * 4.0f;
}
bool IsValidTemperature(float fahrenheit)
{
    return fahrenheit >= 50.0f;
}

// Main
int main() {
    //KittyKatta
    for (int i = 1; i <= 100; i++) {
        std::string formatted_text = "";
        if (i % 3 == 0) {
            formatted_text = "Kitty";
        }
        if (i % 5 == 0) {
            formatted_text = formatted_text + "Katta";
        }
        if (formatted_text == "") {
            formatted_text = std::to_string(i);
        }
        std::cout << formatted_text << std::endl;
    }

    //Chirp Chirp Chirp
    bool isInputValid = false;
    float ChirpsPer15;
    while (!isInputValid) {
        std::cout << "Input Chirps per 15 seconds";
        std::cin >> ChirpsPer15;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number." << std::endl;
        }
        else {
            isInputValid = true;
        }
    }
    int inputTemperature = ChirpsToFahrenheit(ChirpsPer15);
    if (!IsValidTemperature(inputTemperature)) {
        std::cout << "Crickets would not be singing, invalid input." << std::endl;
    }
    else {
        std::cout << "Temperature in Fahrenheit: " << inputTemperature << std::endl;
    }
    return 0;
}