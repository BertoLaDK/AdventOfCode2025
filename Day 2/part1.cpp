#include <fstream>
#include <iostream>
#include <print>
#include <vector>
#include <string>


int main() {
    std::ifstream file("..\\Day 2\\input.txt");

    std::vector<std::uint64_t> invalidIds{};
    std::string inputStr;
    while (std::getline(file, inputStr,',')) {
        std::size_t index = inputStr.find_first_of('-');
        if (index == std::string::npos) {
            continue;
        }
        std::uint64_t firstNumber = std::stoull(inputStr.substr(0, index));
        std::uint64_t secondNumber = std::stoull(inputStr.substr(index + 1));

        for (std::uint64_t i = firstNumber; i <= secondNumber; i++) {
            std::string number = std::to_string(i);

            if (number.size() % 2 != 0) {
                continue;
            }

            std::uint64_t firstHalf = std::stoull(number.substr(0,number.size()/2));
            std::uint64_t secondHalf = std::stoull(number.substr(number.size()/2));
            if (firstHalf == secondHalf) {
                std::println("Invalid num: {}", number);
                invalidIds.push_back(i);
            }
        }
    }
    std::uint64_t invalidSum = 0;
    for (const auto id : invalidIds) {
        invalidSum += id;
    }
    std::println("Sum is {}", invalidSum);
    return 0;
}
