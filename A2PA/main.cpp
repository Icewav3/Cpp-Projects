#include <iostream>
#include <map>
#include <string>
#include "Bioinformatics/Bioinformatics.h"

std::ostream &operator<<(std::ostream &os, const std::map<char, int> &m) {
    for (auto [k, v]: m) {
        os << k << " : " << v << '\n';
    }
    return os;
}

int main() {
    std::string data{
        "AGCTTTTCATTCTGACTGCAACGGGCAATATGTCTCTGTGTGGATTAAAAAAAGAGTGTCTGATAGCAGC"
    };
    std::cout << SumCharacters(data) << '\n';

    //Hamming Distance (std::string)
    const std::string data1{"GAGCCTACTAACGGGAT"};
    const std::string data2{"CATCGTAATGACGGCCT"};
    std::cout << "Hamming Distance: " << CalculateHammingDistance(data1, data2)
            << '\n';
    //Bioinformatics Processing Program
    std::string input1 = "1";
    std::string input2 = "";
    while (input1.length() != input2.length()) {
        std::cout << "Input lengths must be equal." << '\n';
        std::cout << "Enter first sequence: ";
        std::cin >> input1;
        std::cout << "Enter second sequence: ";
        std::cin >> input2;
    }

    //No Function Side Effects: Functions should only alter the state of their own local variables. No function should access or modify a variable outside of its local scope.


    return 0;
}
