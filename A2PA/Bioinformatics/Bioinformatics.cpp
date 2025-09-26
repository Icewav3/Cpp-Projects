#include "Bioinformatics.h"

#include <map>

namespace Bioinformatics {
	/// Counts the frequency of each character in a DNA sequence
	/// Iterates through each character and maintains a count using a map data structure
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

	/// Calculates the Hamming distance between two DNA sequences
	/// Compares sequences character by character and counts mismatches
	int CalculateHammingDistance(std::string data1, std::string data2) {
		int ham = 0;
		for (int i = 0; i < data1.length(); i++) {
			if (data1[i] != data2[i]) {
				ham++;
			}
		}
		return ham;
	}
}
