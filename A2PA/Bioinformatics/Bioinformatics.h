#pragma once
#include <map>
#include <string>

namespace Bioinformatics {
	/// Counts the frequency of each character in a DNA sequence
	/// @param data The input DNA sequence string to analyze
	/// @return A map where keys are characters and values are their occurrence counts
	std::map<char, int> SumCharacters(const std::string &data);

	/// Calculates the Hamming distance between two DNA sequences
	/// The Hamming distance is the number of positions where corresponding characters differ
	/// @param data1 First DNA sequence string
	/// @param data2 Second DNA sequence string
	/// @return The number of differing positions between the two sequences
	int CalculateHammingDistance(std::string data1, std::string data2);
}
