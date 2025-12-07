#include <print>
#include <fstream>
#include <sstream>
#include <string>


int main() {
    std::ifstream file("..\\Day 3\\input.txt");

    std::uint64_t totalJoltage = 0;
    std::string inputStr;
    while (std::getline(file, inputStr)) {
        std::stringstream ss;
        int numberOfBatteriesLeft = 12;
        int lastPos = 0;
        for (int i = numberOfBatteriesLeft; i > 0; i--) {
            int largestBattery = 0;
            for (int j = lastPos; j < inputStr.length() && j <= inputStr.length() - i; j++) {
                int num = inputStr[j] - '0';
                if (num > largestBattery) {
                    largestBattery = num;
                    lastPos = j+1;
                }
            }
            ss << largestBattery;
        }
        std::println("{} contains a joltage of {}", inputStr, ss.str());
        totalJoltage += std::stoll(ss.str());
    }

    std::println("Total Joltage is: {}", totalJoltage);
}
