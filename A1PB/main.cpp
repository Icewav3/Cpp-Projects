#include <iostream>
#include <cctype>
#include <conio.h>
#include <string>
#include <cmath>
#include "Utility.h"
// Functions
int randomNumber(const int min, const int max) {
    const int range = max - min + 1;
    return rand() % range + min;
}

void renderStat(const std::string& label, int statValue, int maxValue, int width, char fill, char empty, bool showRatio, bool showPercentage) {
    int numIndicators = 0;
    std::string statBar{};
    //name & open bar
    statBar += label + " [";
    //calculate number of indicators we need
    float indicatorValue = std::floor(maxValue / width);
    numIndicators = std::floor(statValue / indicatorValue);
    std::string bar = std::string(numIndicators, fill);
    bar += std::string( width - numIndicators, empty);
    //add indicators
    statBar += bar;
    //close bar
    statBar += "] ";
    //Add ratio
    if (showRatio) {
        statBar += std::to_string(statValue) + "/" + std::to_string(maxValue) + " ";
    }
    //Add percentage
    if (showPercentage) {
        int percent = static_cast<float>(statValue)/maxValue*1000.0f;
        percent = clamp(percent, 0, 1000);
        int num = percent / 10;
        int decimal = percent % 10;
        statBar += std::to_string(num) + "." + std::to_string(decimal) + " % ";
    }
    //out value
    std::cout << statBar << std::endl;
}
void renderStat(const std::string& label, int statValue, int maxValue) {
    renderStat(label, statValue, maxValue, 20, '#', '-', true, true);
}
void renderStat(const std::string& label, double percent) {
    renderStat(label, (int)(percent*10), 1000, 20, '#', '-', false, true);
}

// Main
int main() {
    // Guess that number
    bool play = true;
    while (play) {
        int lowerBound = -1;
        int upperBound = 0;
        int guess;
        bool isGuessValid = false;
        std::cout << "Do you want to play a game where you guess a number, that I choose? (y/n)" << std::endl;
        char answer;
        std::cin >> answer;
        if (answer == 'n') {
            play = false;
            break;
        }
        std::cout << "Please enter the lower bounding number" << std::endl;
        while (lowerBound < 0) {
            std::cin >> lowerBound;
            if (lowerBound < 0) {
                std::cout << "Please enter a non negative number" << std::endl;
            }
        }
        while (upperBound <= lowerBound) {
            std::cout << "Please enter the upper bounding number" << std::endl;
            std::cin >> upperBound;
            if (lowerBound > upperBound) {
                std::cout << "upper bound must be more than lower bound" << std::endl;
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
        std::cin >> answer;
        if (answer == 'n') {
            play = false;
        }

    }
    //TUI Stats Bar
    renderStat("Health", 100, 100);
    renderStat("Mana", 25, 100);
    renderStat("Stamina", 0, 100);
    //some overload
    renderStat("Charge", 12.5);
    renderStat("Speed", 27.93);
    //max overload
    renderStat("Apple Power", 10, 20, 10, '*', '_', false, true);
    renderStat("Banana Power", 10, 20, 10, '=', '.', true, true);

    /* Reflection
     *
     *
     * Difficulty/Length
     * p1 = Very easy ~ 20 min
     * p2 = hard took me a long time to go read stuff ~ 90 min
     */
    return 0;
}