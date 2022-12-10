//
// Created by antoni on 12/10/22.
//

#ifndef AOC22_DAY10_H
#define AOC22_DAY10_H

#include <string>
#include <vector>
#include <fstream>
#include <memory>
#include <iostream>
#include <unordered_map>

std::vector<std::pair<bool, int>> read_input(const std::string &filename) {
    std::fstream file(filename);
    std::vector<std::pair<bool, int>> input;
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            if (line[0] == 'a') {
                input.emplace_back(true, std::stoi(std::string(line.substr(5))));
            } else {
                input.emplace_back(false, 0);
            }
        }
    }
    return input;
}

void do_cycle(int rx, int &cycle, int &sum, std::string &output) {
    if (cycle % 40 == 20) {
        sum += rx * cycle;
    }
    if (cycle++ % 40 == 1) {
        output.push_back('\n');
    }
    output.push_back((abs((cycle - 2) % 40 - rx) < 2) ? '#' : '.');
}

void solve_10_1(std::vector<std::pair<bool, int>> &input) {
    int x = 1;
    int sum = 0;
    int cycles = 1;
    std::unordered_map<int, bool> important = {{20,  true},
                                               {60,  true},
                                               {100, true},
                                               {140, true},
                                               {180, true},
                                               {220, true}};
    std::string screen;
    for (auto instruction: input) {
        do_cycle(x, cycles, sum, screen);
        if (instruction.first) {
            do_cycle(x, cycles, sum, screen);
            x += instruction.second;
        }
    }
    std::cout << "Part 1: " << sum << std::endl;
    std::cout << "Part 2: " << screen << std::endl;
}

void solve_10() {
    auto input = read_input("/home/antoni/dev/aoc22/day10/data.txt");
    solve_10_1(input);

}

#endif //AOC22_DAY10_H
