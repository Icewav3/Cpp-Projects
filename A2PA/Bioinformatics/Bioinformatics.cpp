#include "Bioinformatics.h"

#include <map>

std::string GetInput() {
}

std::map<char, int> SumCharacters(const std::string &data) {
	std::map<char, int> count;
	//Base Counts (std::string, std::map)
	for (char i: data) {
		auto [_, boolValue] = count.insert({i, 1});
		if (!boolValue) {
			count[i]++;
		}
	}
	return count;
}

int CalculateHammingDistance(std::string data1, std::string data2) {
	int ham = 0;
	for (int i = 0; i < data1.length(); i++) {
		if (data1[i] != data2[i]) {
			ham++;
		}
	}
	return ham;
}
