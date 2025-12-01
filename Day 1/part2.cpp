#include <fstream>
#include <iostream>
#include <print>
#include <string>

int dialPos = 50;
int numberOfZeros = 0;

void turnDial(char dir, int steps) {
    int startPos = dialPos;
    bool overflow = false;
    if (dir == 'L') {
        dialPos -= steps;
    } else {
        dialPos += steps;
    }
    while (dialPos < 0) {
        dialPos = 100 + dialPos;
        if (startPos != 0 && !overflow) {
            numberOfZeros++;
        }
        std::println("It passed 0");
        overflow = true;
    }
    while (dialPos > 99) {
        dialPos = dialPos - 100;
        if (startPos != 0 && !overflow) {
            numberOfZeros++;
        }
        std::println("It passed 0");
        overflow = true;
    }
    if (dialPos == 0 && !overflow) {
        numberOfZeros++;
        std::println("It stopped at 0");
    }
}


int main() {
    std::ifstream file("..\\Day 1\\input.txt");
    std::string str;
    while (std::getline(file, str)) {
        char dir = str.at(0);
        int steps = std::stoi(str.substr(1, str.length()));
        turnDial(dir, steps);
        std::println("The Dial is rotated {} to position: {}", str, dialPos);
    }
    std::println("Number of zeros = {}", numberOfZeros);
    return 0;
}
