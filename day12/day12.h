//
// Created by antoni on 12/12/22.
//

#ifndef AOC22_DAY12_H
#define AOC22_DAY12_H

#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <optional>
#include <queue>
#include <tuple>

struct coord_t {
    int x;
    int y;
};

coord_t operator+(const coord_t &c1, const coord_t &c2) {
    return {c1.x + c2.x, c1.y + c2.y};
}

bool operator<(const coord_t &a, const coord_t &b) {
    return std::make_tuple(a.x, a.y) < std::make_tuple(b.x, b.y);
}

std::vector<coord_t> directions{{-1, 0},
                                {1,  0},
                                {0,  -1},
                                {0,  1}};

class grid_t {
public:
    std::vector<int> heights;
    int width;
    int height;

    grid_t(const std::vector<int> &_heights, int _width, int _height);

    explicit grid_t(const std::string &filename, bool debug);

    [[nodiscard]] int get(const coord_t &c) const;

    [[nodiscard]] int get_height(const coord_t &c) const;

    void set(const coord_t &c, int value);

    [[nodiscard]] bool within_bounds(const coord_t &c) const;

    [[nodiscard]] bool able_to_move(const coord_t &c1, const coord_t &c2, bool l_to_h) const;

    coord_t get_height(char c);

};

int grid_t::get(const coord_t &c) const {
    return heights[c.y * width + c.x];
}

int grid_t::get_height(const coord_t &c) const {
    int h = get(c);
    return h == 'S' ? 'a' : h == 'E' ? 'z' : h;
}

void grid_t::set(const coord_t &c, int value) {
    heights[c.y * width + c.x] = value;
}

bool grid_t::within_bounds(const coord_t &c) const {
    return c.x >= 0 && c.x < width && c.y >= 0 && c.y < height;
}

bool grid_t::able_to_move(const coord_t &c1, const coord_t &c2, bool l_to_h) const {
    if (l_to_h) {
        return get_height(c2) - get_height(c1) <= 1;
    } else {
        return get_height(c1) - get_height(c2) <= 1;
    }
}

grid_t::grid_t(const std::string &filename, bool debug = false) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            for (auto &ch: line) {
                heights.push_back(ch);
            }
            width = (int) line.size();
        }
    }
    file.close();
    height = (int) heights.size() / width;
    if (debug) {
        std::cout << "created grid with width " << width << " and height " << height << std::endl;
    }
}

coord_t grid_t::get_height(char c) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (heights[i * width + j] == c) {
                return {static_cast<int>(j), static_cast<int>(i)};
            }
        }
    }
    return {-1, -1};
}

grid_t::grid_t(const std::vector<int> &_heights, int _width, int _height) {
    heights = _heights;
    width = _width;
    height = _height;
}

auto bfs(const grid_t &grid, const coord_t start, char dest, bool l_to_h) {
    std::queue<coord_t> queue;

    grid_t visited{std::vector<int>(grid.height * grid.width, 0), grid.width, grid.height};
    grid_t steps{std::vector<int>(grid.height * grid.width, 0), grid.width, grid.height};

    steps.set(start, 0);
    queue.push(start);

    while (!queue.empty()) {
        auto cur = queue.front();
        queue.pop();

        if (grid.get(cur) == dest) {
            return steps.get(cur);
        }
        if (visited.get(cur)) {
            continue;
        }
        visited.set(cur, 1);
        for (auto &dir: directions) {
            coord_t new_pos = cur + dir;
            if (grid.within_bounds(new_pos) && !visited.get(new_pos) && grid.able_to_move(cur, new_pos, l_to_h)) {
                steps.set(new_pos, steps.get(cur) + 1);
                queue.push(new_pos);
            }
        }
    }
    return -1;
}


void solve_12_1() {
    // create a new instance of the grid
    grid_t grid("/home/antoni/dev/aoc22/day12/data.txt", true);
    coord_t start = grid.get_height('S');
    std::cout << bfs(grid, start, 'E', true) << std::endl;
}

void solve_12_2() {
    // create a new instance of the grid
    grid_t grid("/home/antoni/dev/aoc22/day12/data.txt", true);
    coord_t start = grid.get_height('E');
    std::cout << bfs(grid, start, 'a', false) << std::endl;
}

void solve_12() {
    std::cout << "Day 12" << std::endl;
    std::cout << "--------------------------" << std::endl;
    solve_12_1();
    std::cout << "--------------------------" << std::endl;
    solve_12_2();
}

#endif //AOC22_DAY12_H
