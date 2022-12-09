//
// Created by antoni on 12/8/22.
//

#ifndef AOC22_DAY8_H
#define AOC22_DAY8_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

std::vector<std::vector<int>> *readInput(const std::string &filename) {
    auto *heights = new std::vector<std::vector<int>>();
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        auto *row = new std::vector<int>;
        for (char i: line) {
            row->push_back(std::stoi(std::string(1, i)));
        }
        heights->push_back(*row);
    }
    return heights;
};

int visible_from(const std::vector<std::vector<int>> &heights, int x, int y) {
    int height = (int) heights.size();
    int width = (int) heights[0].size();
    int tree_height = heights[y][x];
    if (x == 0 || y == 0 || x == width - 1 || y == height - 1) {
        return 0;
    }
    int left, right, up, down; // visible trees to each direction
    // this is horrific
    // up
    up = 0;
    for (int i = y - 1; i != -1; i -= 1, ++up) {
        if (heights[i][x] >= height) {
            ++up;
            break;
        }
    }
    // down
    down = 0;
    for (int i = y + 1; i != height; i += 1, ++down) {
        if (heights[i][x] >= height) {
            ++down;
            break;
        }
    }
    // left
    left = 0;
    for (int i = x - 1; i != -1; i -= 1, ++left) {
        if (heights[y][i] >= height) {
            ++left;
            break;
        }
    }
    //right
    right = 0;
    for (int i = x + 1; i != width; i += 1, ++right) {
        if (heights[y][i] >= height) {
            ++right;
            break;
        }
    }
    int scenic = up * down * left * right;
    return scenic;
}
bool is_visible(const std::vector<std::vector<int>> &heights, int x, int y) {
    int height = (int) heights.size();
    int width = (int) heights[0].size();
    int tree_height = heights[y][x];
    if (x == 0 || y == 0 || x == width - 1 || y == height - 1) {
        return true; // check if on edge of forest, must be visible
    }
    bool up, down, left, right;
    // this was a massive pain to write
    // up
    up = true;
    for (int i = y - 1; i != -1; i -= 1) {
        if (heights[i][x] >= tree_height) {
            up = false;
        }
    }
    // down
    down = true;
    for (int i = y + 1; i != height; i += 1) {
        if (heights[i][x] >= tree_height) {
            down = false;
        }
    }
    //left
    left = true;
    for (int i = x - 1; i != -1; i -= 1) {
        if (heights[y][i] >= tree_height) {
            left = false;
        }
    }
    // right
    right = true;
    for (int i = x + 1; i != width; i += 1) {
        if (heights[y][i] >= tree_height) {
            right = false;
        }
    }
    return up || down || left || right;
}

void solve_8_part1() {
    auto *input = readInput("/home/antoni/dev/aoc22/day8/data.txt");
    // check each tree if visible
    int visible = 0;
    for (int y = 0; input->size() > y; ++y) {
        for (int x = 0; x < input[0].size(); ++x) {
            visible += is_visible(*input, x, y);
        }
    }
    std::cout << "Part 1: " << visible << std::endl;
}

void solve_8_part2() {
    auto *input = readInput("/home/antoni/dev/aoc22/day8/data.txt");
    int highest = 0;
    for (int y= 0; y < input->size(); ++y) {
        for (int x = 0; x < input[0].size(); ++x) {
            highest = std::max(highest, visible_from(*input, x, y));
        }
    }
    std::cout << "Part 2: " << highest << std::endl;
}

void solve_8() {
    solve_8_part1();
    solve_8_part2();
}

#endif //AOC22_DAY8_H
