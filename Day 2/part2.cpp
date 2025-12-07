#include <execution>
#include <fstream>
#include <iostream>
#include <print>
#include <vector>
#include <string>


int main() {
    std::ifstream file("..\\Day 2\\input.txt");

    std::vector<std::uint64_t> invalidIds{};
    std::string inputStr;
    while (std::getline(file, inputStr, ',')) {
        std::size_t index = inputStr.find_first_of('-');
        if (index == std::string::npos) {
            continue;
        }
        std::uint64_t firstNumber = std::stoull(inputStr.substr(0, index));
        std::uint64_t secondNumber = std::stoull(inputStr.substr(index + 1));

        for (std::uint64_t i = firstNumber; i <= secondNumber; i++) {
            std::string number = std::to_string(i);
            for (std::size_t j = number.size() / 2; j >= 1; j--) {
                auto pattern = number.substr(0, j);
                auto patternLength = pattern.size();
                float patternRepeats = static_cast<float>(number.size()) / static_cast<float>(patternLength);
                if (std::floor(patternRepeats) != patternRepeats) {
                    continue;
                }
                bool isValid = true;
                for (std::size_t k = 1; k < number.size() / patternLength; k++) {
                    auto partCompare = number.substr(k * patternLength, j);
                    if (pattern != partCompare) {
                        isValid = false;
                        break;
                    }
                }
                if (isValid) {
                    invalidIds.push_back(i);
                    std::println("Is Valid: {}", i);
                    break;
                }
            }
        }
    }
    std::uint64_t invalidSum = 0;
    for (const auto id: invalidIds) {
        invalidSum += id;
    }
    std::println("Sum is {}", invalidSum);
    return 0;
}
