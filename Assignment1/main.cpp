#include <iostream>
// Functions
float FahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32.0f) * 5.0f / 9.0f;
}
float CelsiusToFahrenheit(float celsius)
{
    return celsius * (9.0f / 5.0f) + 32.0f;
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
    std::string inputTemperature;
    std::cout << "Input temperature as a format of NumberTemperatureType, Ex. 14f";
    bool isInputValid = false;
    while (!isInputValid) {
        std::cin >> inputTemperature;
        isInputValid = true;
        char lastCharOfInput = inputTemperature[inputTemperature.length()-1];
        lastCharOfInput = tolower(lastCharOfInput);
        if (lastCharOfInput == 'c' || lastCharOfInput == 'f') {
            for (int i = 0; i < inputTemperature.length() - 1; i++) {
                if (!std::isdigit(inputTemperature[i])) {
                    std::cout << "Invalid input, Ex. 14f";
                    isInputValid = false;
                    break;
                }
            }
        }
        else {
            isInputValid = false;
            std::cout << "Missing unit, Ex. 14f";
            break;
        }
    }
    if (isInputValid) {
        std::cout << inputTemperature.substr(0, inputTemperature.length()-1);
    }

    return 0;
}