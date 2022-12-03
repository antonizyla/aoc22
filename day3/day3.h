//
// Created by antoni on 12/3/22.
//

#ifndef AOC22_DAY3_H
#define AOC22_DAY3_H

#include <string>
#include <fstream>
#include <unordered_map>
#include <iostream>
#include <vector>

void solve_3_1(const std::string &filename) {
    std::ifstream file(filename);
    std::string line;
    int priority = 0;
    if (file.is_open()) {
        while (std::getline(file, line)) {
            std::unordered_map<int, bool> h1;
            for (int i = 0; i < (int) (line.size() / 2); i++) {
                h1[line[i]] = true;
            }
            for (int j = (int) (line.size() / 2); j < (int) line.size(); j++) {
                if (h1[line[j]]) {
                    if (line[j] >= 65 && line[j] <= 90) {
                        priority += (int) (line[j]) - 38;
                        h1[line[j]] = false;
                    } else if (line[j] >= 97 && line[j] <= 122) {
                        priority += (int) (line[j]) - 96;
                        h1[line[j]] = false;
                    }
                }
            }
        }
    }
    std::cout << "Part 1: " << std::endl;
    std::cout << "Priority: " << priority << std::endl;
}

void solve_3_2(const std::string &filename) {
    std::ifstream file(filename);
    std::string line;
    std::vector<std::pair<std::string, std::unordered_map<int, bool>>> lines;
    lines.reserve(400);
    for (auto &i: lines) {
        i.first.reserve(50); //reserve 50 chars per line
    }
    if (file.is_open()) {
        while (std::getline(file, line)) {
            lines.emplace_back(line, std::unordered_map<int, bool>());
        }
    }
    for (auto &pair: lines) {
        for (auto &character: pair.first) {
            pair.second[character] = true;
        }
    }
    int priority = 0;
    for (int i = 0; i < lines.size(); i += 3) {
        // for each set of 3 elves
        for (auto &[key, value]: lines[i].second) {
            if (lines[i + 1].second[key] && lines[i + 2].second[key]) {
                if (key >= 65 && key <= 90) {
                    priority += (int) (key) - 38;
                    lines[i].second[key] = false;
                    lines[i + 1].second[key] = false;
                    lines[i + 2].second[key] = false;
                } else if (key >= 97 && key <= 122) {
                    priority += (int) (key) - 96;
                    lines[i].second[key] = false;
                    lines[i + 1].second[key] = false;
                    lines[i + 2].second[key] = false;
                }
            }
        }
    }
    std::cout << "Part 2: " << std::endl;
    std::cout << "Priority: " << priority << std::endl;
}


void solve_3() {
    solve_3_1("/home/antoni/dev/aoc22/day3/data.txt");
    solve_3_2("/home/antoni/dev/aoc22/day3/data.txt");
}

#endif //AOC22_DAY3_H
