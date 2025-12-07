#include <print>
#include <fstream>
#include <string>


int main() {
    std::ifstream file("..\\Day 3\\input.txt");

    int totalJoltage = 0;
    std::string inputStr;
    while (std::getline(file, inputStr)) {
        int first = 0;
        int firstPos = 0;
        int second = 0;
        for (int i = 0; i < inputStr.length()-1; i++) {
            int num = inputStr[i] - '0';
            if (num > first) {
                firstPos = i;
                first = num;
            }
        }
        for (int i = firstPos + 1; i < inputStr.length(); i++) {
            int num = inputStr[i] - '0';
            if (num > second) {
                second = num;
            }
        }
        std::println("Joltage of {} is {}{}",inputStr, first, second);
        totalJoltage += std::stoi(std::format("{}{}",first,second));
    }

    std::println("Total Joltage is: {}",totalJoltage);
}
