#include <fstream>
#include <iostream>
#include <print>
#include <string>

int dialPos = 50;
void turnDial(char dir, int steps) {
    if (dir == 'L') {
        dialPos -= steps;
    } else {
        dialPos += steps;
    }
    while (dialPos < 0) {
        dialPos = 100 + dialPos;
    }
    while (dialPos > 99) {
        dialPos = dialPos - 100;
    }
}

int numberOfZeros = 0;

int main() {
    std::ifstream file("..\\Day 1\\input.txt");
    std::string str;
    while (std::getline(file, str)) {
        char dir = str.at(0);
        int steps = std::stoi(str.substr(1, str.length()));
        turnDial(dir, steps);
        std::println("The Dial is rotated {} to position: {}", str, dialPos);
        if (dialPos == 0) {
            numberOfZeros++;
        }
    }
    std::println("Number of zeros = {}", numberOfZeros);
    return 0;
}
