#include <iostream>
#include <limits>
#include <cctype>
#include <conio.h>

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
bool hasLowerCase(const std::string& password) {
    for (char c : password) {
        if (std::islower(c)) {
            return true;
        }
    }
    return false;
}

bool hasUpperCase(const std::string& password) {
    for (char c : password) {
        if (std::isupper(c)) {
            return true;
        }
    }
    return false;
}

bool hasNumber(const std::string& password) {
    for (char c : password) {
        if (std::isdigit(c)) {
            return true;
        }
    }
    return false;
}
std::string getPassword() {
    std::string password;
    char input = 0;
    std::cout << std::endl;
    while (true) {
        input = _getch();
        if (input == 13) {
            std::cout << std::endl;
            break;
        }
        else if (input == 8) {
            if (password.length() > 0) {
                password.pop_back();
                std::cout << "\b \b";
            }
        }
        else {
            password += input;
            std::cout << "*";
            std::cout.flush();
        }
    }
    return password;
}
int randomNumber(const int min, const int max) {
    const int range = max - min + 1;
    return rand() % range + min;
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
        // fancy thing that prevents crash on invalid user input
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
    // Please Choose a Password

    std::string SavedPassword;
    bool isValidPassword = false;
    bool passwordConfirmed = false;
    // Clear input buffer before password input
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    while (!passwordConfirmed) {
        while (!isValidPassword) {
            std::string password;
            std::cout << "Please choose a password: ";
            password = getPassword();
            if (password.length() < 8) {
                std::cout << "Password must be at least 8 characters long" << std::endl;
                continue;
            }
            if (!hasUpperCase(password)) {
                std::cout << "Password must contain at least one uppercase letter" << std::endl;
                continue;
            }
            if (!hasNumber(password)) {
                std::cout << "Password must contain at least one number" << std::endl;
                continue;
            }
            if (!hasLowerCase(password)) {
                std::cout << "Password must contain at least one lowercase letter" << std::endl;
                continue;
            }
            SavedPassword = password;
            isValidPassword = true;

        }
        std::cout << "Password accepted. Please re-type password";
        std::string password;
        password = getPassword();
        if (SavedPassword == password) {
            std::cout << "Success, New password: " + SavedPassword << std::endl;
            passwordConfirmed = true;
        }
        else {
            std::cout << "Passwords do not match. Please try again" << std::endl;
        }
    }
    // Guess that number
    bool play = true;
    while (play) {
        int lowerBound;
        int upperBound;
        int guess;
        bool isGuessValid = false;
        std::cout << "Lets play a game where you guess a number I choose" << std::endl;
        std::cout << "Please enter the upper bounding number" << std::endl;
        std::cin >> upperBound;
        while (upperBound <= lowerBound || !lowerBound || lowerBound < 0) {
            std::cout << "Please enter the lower bounding number" << std::endl;
            std::cin >> lowerBound;
            if (lowerBound > upperBound) {
                std::cout << "lower bound must be less than upper bound" << std::endl;
            }
        }
        int numberToGuess = randomNumber(lowerBound, upperBound);
        std::cout << "I've chosen a number! Try to guess" << std::endl;
        while (!isGuessValid) {
            std::cin >> guess;
            if (guess > numberToGuess) {
                std::cout << "Too high" << std::endl;
            }
            else if (guess < numberToGuess) {
                std::cout << "Too low" << std::endl;
            }
            else if (guess == numberToGuess){
                std::cout << "You guessed it!" << std::endl;
                isGuessValid = true;
            }
            else {
                std::cout << "How did we get here?" << std::endl;
            }
        }
        std::cout << "Would you like to play again? (y/n)" << std::endl;
        char answer;
        std::cin >> answer;
        if (answer == 'y') {
            play = true;
        }
        else {
            play = false;
        }
    }

    /* Reflection
     * Debugging was kind of annoying, only mildly - since I had to constantly change a bool to prevent code running
     *
     * Difficulty/Length
     * p1 = Very easy ~ 5 min
     * p2 = hard (found this one especially difficult) ~ 40 min
     * p3 = easy ~ 10 min
     * p4 = medium ~ 20 min
     *
     */
    return 0;
}