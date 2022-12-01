//
// Created by antoni on 12/1/22.
//

#ifndef AOC22_DAY1_H
#define AOC22_DAY1_H

#include <fstream>
#include <vector>
#include <algorithm>

std::vector<int> read_file(const std::string &filename) {
    std::string line;
    std::ifstream file(filename);
    std::vector<int> counts;
    counts.reserve(400);
    if (file.is_open()) {
        int currentCount = 0;
        while (std::getline(file, line)) {
            if (line.empty()) {
                counts.push_back(currentCount);
                currentCount = 0;
            } else {
                currentCount += std::stoi(line);
            }
        }
        counts.push_back(currentCount);
        file.close();
    }
    return counts;
}

void solve_day1_2(std::vector<int> counts, bool fast = true) {
    int sum = 0;
    if (fast) {
        // O(n) solution
        int first = 0;
        int second = 0;
        int third = 0;
        for (int current: counts) {
            if (current > first) {
                third = second;
                second = first;
                first = current;
            } else if (current > second) {
                third = second;
                second = current;
            } else if (current > third) {
                third = current;
            }
        }
        sum = first + second + third;
        std::cout << "Part 2 Solution (Fast) : " << std::endl;
    } else {
        // O(n log n) solution
        std::sort(counts.begin(), counts.end());
        for (int i = counts.size() - 1; i >= counts.size() - 3; i--) {
            sum += counts[i];
        }
        std::cout << "Part 2 Solution : " << std::endl;
    }
    std::cout << "Top 3 Sum: " << sum << std::endl;
}

void solve_day1_1(std::vector<int> &counts) {
    int max = 0;
    int index = 0;
    for (int i = 0; i < counts.size(); i++) {
        if (counts[i] > max) {
            max = counts[i];
            index = i;
        }
        std::cout << counts[i] << std::endl;
    }
    std::cout << "Part 1 Solution: " << std::endl;
    std::cout << "Max: " << max << " Index: " << index << std::endl;
}

bool solve_1() {
    std::vector data = read_file("/home/antoni/dev/aoc22/day1/data.txt");
    solve_day1_1(data);
    solve_day1_2(data);
    solve_day1_2(data, false);
}

#endif //AOC22_DAY1_H
