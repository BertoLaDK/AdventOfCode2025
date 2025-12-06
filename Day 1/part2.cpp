#include <fstream>
#include <iostream>
#include <print>
#include <string>

int dialPos = 50;
int numberOfZeros = 0;

void turnDial(char dir, int steps) {
    int mod = steps % 100;
    int rotations = std::floor(steps / 100.0f);
    if (dir == 'L') {
        dialPos -= mod;
    } else {
        dialPos += mod;
    }
    if (dialPos > 99) {
        dialPos = dialPos - 100;
        if (dialPos != 0) {
            numberOfZeros++;
        }
    } else if (dialPos < 0) {
        dialPos = dialPos + 100;
        if (dialPos != 0) {
            numberOfZeros++;
        }
    }
    numberOfZeros += rotations;
    if (dialPos == 0) {
        numberOfZeros++;
    }
    std::println("Mod: {}, Rotations: {}, Steps: {} | DialPos: {}", mod, rotations, steps, dialPos);
}


void turnDialOneAtAtime(char dir, int steps) {
    int step = 1;
    if (dir == 'L') {
        step = -1;
    }
    for (int i = 0; i < steps; i++) {
        dialPos += step;
        if (dialPos > 99) {
            dialPos = 0;
        }
        if (dialPos < 0) {
            dialPos = 100 + dialPos;
        }
        if (dialPos == 0) {
            numberOfZeros++;
        }
    }
}

int main() {
    std::ifstream file("..\\Day 1\\input.txt");
    std::string str;
    while (std::getline(file, str)) {
        char dir = str.at(0);
        int steps = std::stoi(str.substr(1, str.length()));
        turnDial(dir, steps);
    }
    std::println("Number of zeros = {}", numberOfZeros);
    return 0;
}
