#pragma once
#include <map>
#include <string>

std::string GetInput();

std::map<char, int> SumCharacters(const std::string &data);

int CalculateHammingDistance(std::string data1, std::string data2);
