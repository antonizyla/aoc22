//
// Created by antoni on 12/9/22.
//

#ifndef AOC22_DAY9_H
#define AOC22_DAY9_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <unordered_map>

std::vector<std::pair<char, int>> read_input(const std::string &filename) {
    std::ifstream file(filename);
    std::vector<std::pair<char, int>> input;
    std::string line;
    if (file.is_open()) {
        while (std::getline(file, line)) {
            input.emplace_back(line[0], std::stoi(line.substr(1)));
            std::cout << line[0] << " " << std::stoi(line.substr(1)) << std::endl;
        }
    }
    return input;
}

struct pair_hash {
    template<class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2> &pair) const {
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
};

void
update_tail_pos(int cy, int cx, int &ty, int &tx, std::unordered_map<std::pair<int, int>, int, pair_hash> &tail_pos) {
    int dx = cx - tx;
    int dy = cy - ty;
    if ((std::abs(dx) + std::abs(dy)) > 2) {
        tx += (dx > 0 ? 1 : -1);
        ty += (dy > 0 ? 1 : -1);
    } else if (std::abs(dx) > 1) {
        tx += (dx > 0 ? 1 : -1);
    } else if (std::abs(dy) > 1) {
        ty += (dy > 0 ? 1 : -1);
    } else {
        return;
    }
    if (!tail_pos.contains({ty, tx})) {
        tail_pos[{tx, ty}]++;
    } else {
        tail_pos[{tx, ty}] = 1;
    }
}


std::pair<int, int> updated_tail_position(int cy, int cx, std::pair<int, int> current) {
    int dx = cx - current.first;
    int dy = cy - current.second;
    if ((std::abs(dx) + std::abs(dy)) > 2) {
        current.first += (dx > 0 ? 1 : -1);
        current.second += (dy > 0 ? 1 : -1);
    } else if (std::abs(dx) > 1) {
        current.first += (dx > 0 ? 1 : -1);
    } else if (std::abs(dy) > 1) {
        current.second += (dy > 0 ? 1 : -1);
    }
    return current;
}

void solve_9() {
    auto inputs = read_input("/home/antoni/dev/aoc22/day9/data.txt");
    int cx = 0; // imaginary grid positions
    int cy = 0;
    int tx = 0;
    int ty = 0;
    std::unordered_map<std::pair<int, int>, int, pair_hash> grid;
    for (auto &input: inputs) {
        switch (input.first) {
            case 'U':
                for (int i = 0; i < input.second; i++) {
                    cy += 1;
                    update_tail_pos(cy, cx, ty, tx, grid);
                }
                break;
            case 'D':
                for (int i = 0; i < input.second; i++) {
                    cy -= 1;
                    update_tail_pos(cy, cx, ty, tx, grid);
                }
                break;
            case 'L':
                for (int i = 0; i < input.second; i++) {
                    cx -= 1;
                    update_tail_pos(cy, cx, ty, tx, grid);
                }
                break;
            case 'R':
                for (int i = 0; i < input.second; i++) {
                    cx += 1;
                    update_tail_pos(cy, cx, ty, tx, grid);
                }
                break;
        }
    }
    std::cout << grid.size() << std::endl;
}

#endif //AOC22_DAY9_H
