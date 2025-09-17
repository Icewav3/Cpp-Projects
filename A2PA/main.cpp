#include <iostream>
#include <map>
#include <string>
using namespace std::string_literals;

std::ostream& operator<<(std::ostream& os, const std::map<char, int>& m) {
    for (auto [k, v] : m) {
        os << k << " : " << v << '\n';
    }
    return os;
}

int main(){
    std::string data{"AGCTTTTCATTCTGACTGCAACGGGCAATATGTCTCTGTGTGGATTAAAAAAAGAGTGTCTGATAGCAGC"};
    std::map<char, int> count;
    //Bioinformatics
    //Base Counts (std::string, std::map)
    for (char & i : data) {
        auto [_, boolValue] = count.insert({i, 1});
        if (!boolValue) {
            count[i]++;
        }
    }
    std::cout << count << '\n';
    //Hamming Distance (std::string)
    //Bioinformatics Processing Program

    return 0;
}