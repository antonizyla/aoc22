//
// Created by antoni on 12/2/22.
//

#ifndef AOC22_DAY2_H
#define AOC22_DAY2_H

#include <string>
#include <fstream>
#include <iostream>
#include <unordered_map>

void solve_day_2_1_2(const std::string &filename) {
    std::unordered_map<std::string, int> values = {
            {"A X", 4},
            {"A Y", 8},
            {"A Z", 3},
            {"B X", 1},
            {"B Y", 5},
            {"B Z", 9},
            {"C X", 7},
            {"C Y", 2},
            {"C Z", 6},
    };
    // what moves to play to win when opponent is key
    std::unordered_map<char, std::string> toWin = {
            {'A', "Y"},
            {'B', "Z"},
            {'C', "X"},
    };
    // what moves to play to lose when opponent is key
    std::unordered_map<char, std::string> toLose = {
            {'A', "Z"},
            {'B', "X"},
            {'C', "Y"},
    };

    std::ifstream file(filename);
    int a = 0;
    int b = 0;
    std::string line;
    if (file.is_open()) {
        while (std::getline(file, line)) {
            // Opponent A B C -> Rock Paper Scissors
            // Player   X Y Z -> Rock Paper Scissor
            a += values[line];
            switch (line[2]) { // switch for desired outcome
                case 'X': // want to lose
                    b += values[std::string() + line[0] + line[1] + toLose[line[0]]];
                    break;
                case 'Y': // want to tie
                    b += values[std::string() + line[0] + line[1] + (char) (line[0] + 23)];
                    break;
                case 'Z': // want to win
                    b += values[std::string() + line[0] + line[1] + toWin[line[0]]];
                    break;
            }

        }
    }
    std::cout << "Score A: " << a << std::endl;
    std::cout << "Score B: " << b << std::endl;
}

void solve_2() {
    solve_day_2_1_2("/home/antoni/dev/aoc22/day2/data.txt");
}

#endif //AOC22_DAY2_H
