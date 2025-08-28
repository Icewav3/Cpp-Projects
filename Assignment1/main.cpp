#include <iostream>
int main() {
    auto lang = "C++";
    std::cout << "Hello and welcome to " << lang << "!\n";

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

    return 0;
}