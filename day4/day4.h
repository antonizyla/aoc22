//
// Created by antoni on 12/4/22.
//

#ifndef AOC22_DAY4_H
#define AOC22_DAY4_H

#include <string>
#include <fstream>
#include <vector>
#include <tuple>
#include <iostream>
#include <sstream>

void solve_4_1(const std::string &filename) {
    std::ifstream file(filename);
    std::string line;
    std::vector<std::pair<int, int>> ranges;
    if (file.is_open()) {
        while (std::getline(file, line)) {
            std::istringstream s(line);
            std::string pair_string;
            while (std::getline(s, pair_string, ',')) {
                ranges.emplace_back(std::stoi(pair_string.substr(0, pair_string.find('-'))),
                                    std::stoi(pair_string.substr(pair_string.find('-') + 1)));
            }
        }
    }
    int count = 0;
    for (int i = 0; i < ranges.size(); i += 2) {
        int r1s = ranges[i].first;
        int r1e = ranges[i].second;
        int r2s = ranges[i + 1].first;
        int r2e = ranges[i + 1].second;
        if ((r1e <= r2e && r1s >= r2s) || (r2e <= r1e && r2s >= r1s)) {
            count++;
        }
    }
    std::cout << "Part 1 : " << count << std::endl;
}

bool overlap(std::pair<std::pair<int, int>, std::pair<int, int>> pair) {
    int s1 = pair.first.first;
    int e1 = pair.first.second;
    int s2 = pair.second.first;
    int e2 = pair.second.second;
    // check if overlaps
    if (((s2 > e2 && e2 > s2) || (s1 < e1 && e1 < s2)) || ((e1 <= e2 && s1 >= s2) || (e2 <= e1 && s2 >= s1))){
        return false;
    }
    return true;
}

void solve_4_2(const std::string &filename) {
    std::ifstream file(filename);
    std::string line;
    std::vector<std::pair<int, int>> ranges;
    if (file.is_open()) {
        while (std::getline(file, line)) {
            std::istringstream s(line);
            std::string pair_string;
            while (std::getline(s, pair_string, ',')) {
                ranges.emplace_back(std::stoi(pair_string.substr(0, pair_string.find('-'))),
                                    std::stoi(pair_string.substr(pair_string.find('-') + 1)));
            }
        }
    }
    int count = 0;
    for (int i = 0; i < ranges.size(); i += 2) {
        if(!overlap(std::make_pair(ranges[i], ranges[i + 1]))){
            count++;
        }
    }
    std::cout << "Part 2 : " << count << std::endl;
}


void solve_4() {
    solve_4_1("/home/antoni/dev/aoc22/day4/data.txt");
    solve_4_2("/home/antoni/dev/aoc22/day4/data.txt");
}

#endif //AOC22_DAY4_H
