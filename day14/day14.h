//
// Created by antoni on 12/19/22.
//

#ifndef AOC22_DAY14_H
#define AOC22_DAY14_H

#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>

enum state {
    empty,
    wall,
    filled
};

using point = std::pair<int, int>; // x, y coord

point operator+(point p1, point p2) {
    return point(p1.first + p2.first, p1.second + p2.second);
}

class map {
public:
    std::map<point, state> map;
    int width = 0;
    int height = 0;
    point start = {500, 0};
    int poured = 0;
    bool filled_all = false;
    const point down = {0, 1};
    const point adj_left = {-1, 1};
    const point adj_right = {1, 1};

    void print_map() {
        for (int y = 0; y <= height; y++) {
            for (int x = 0; x <= width; x++) {
                if (map[{x, y}] == empty) {
                    std::cout << ".";
                } else if (map[{x, y}] == wall) {
                    std::cout << "#";
                } else {
                    std::cout << 'o';
                }
            }
            std::cout << std::endl;
        }
        std::cout << "Width: " << width << "," << " Height: " << height << std::endl;
    }

    void simulate_sand(point start) {
        bool at_rest = false;
        point cur = start;
        while (!at_rest) {
            if (map[cur + down] == empty) {
                cur = cur + down;
            } else if (map[cur + adj_left] == empty) {
                cur = cur + adj_left;
            } else if (map[cur + adj_right] == empty) {
                cur = cur + adj_right;
            } else {
                if (map.contains(cur)){
                    map[cur] = filled;
                }else{
                    filled_all = true;
                }
                at_rest = true;
                poured +=1;
            }
        }
        std::cout << poured<<std::endl;
    }

    void simulate_2(point start){
        bool at_rest = false;
        point cur = start;
        while (!at_rest) {
            if (map[cur + down] == empty) {
                cur = cur + down;
            } else if (map[cur + adj_left] == empty) {
                cur = cur + adj_left;
            } else if (map[cur + adj_right] == empty) {
                cur = cur + adj_right;
            } else {
                if (!(cur == start)){
                    map[cur] = filled;
                }else{
                    filled_all = true;
                }
                at_rest = true;
                poured +=1;
            }
        }
        std::cout << poured<<std::endl;
    }

    void fill_2(){
        for (int y = 0; y <= height+2; y++){
            for (int x = -1000; x <= width+1000; x++){
                if (!map.contains(point({x,y}))){
                    map[{x,y}] = empty;
                }
                if (y == height+2){
                    map[{x,y}] = wall;
                }
            }
        }
        width+=1000;
        height+=2;
    }

    void part1() {
        while (!filled_all) {
            simulate_sand(start);
        }
    }

    void part2(){
        while (!filled_all){
            simulate_2(start);
        }
    }

    void fill_empty() {
        //std::cout << width << height << std::endl;
        for (int x = 0; x < width; x++) {
            for (int y = 0; y < height; y++) {
                if (!map.contains({x, y})) {
                    map[{x, y}] = empty;
                }
            }
        }
        std::cout << "fill empty done";
    }

    void insert(point p, state s) {
        map[p] = s;
    }

    void insert_range(point p1, point p2) {
        if (p1.first == p2.first) {
            // if vertical
            int start = std::min(p1.second, p2.second);
            int end = std::max(p1.second, p2.second); // y values
            if (end > height) {
                height = end;
                //std::cout << "new height: " << end << std::endl;
            }
            for (int i = start; i <= end; ++i) {
                insert({p1.first, i}, wall);
                //std::cout << p1.first << " " << i  << std::endl;
            }
        } else {
            // if horizontal
            int start = std::min(p1.first, p2.first);
            int end = std::max(p1.first, p2.first);
            if (end > width) {
                width = end;
                //std::cout << "new width: "<< end << std::endl;
            }
            for (int i = start; i <= end; ++i) {
                insert({i, p1.second}, wall);
                //std::cout << i << " " << p1.second << std::endl;
            }
        }
    }

    static std::vector<point> split_line(std::basic_string<char> line) {
        std::vector<point> points;
        std::string token;
        std::vector<std::string> tokens;
        std::stringstream ss(line.data());
        while (ss >> token) {
            tokens.push_back(token);
        }
        for (int i = 0; i < tokens.size(); i += 2) {
            points.push_back(parse_coord(tokens[i]));
        }
        return points;
    }

    static point parse_coord(std::string_view strv) {
        if (strv[0] == ' ') {
            strv.remove_prefix(1);
        }
        uint c = strv.find(',');
        uint e = strv.find('-');
        int x = std::stoi(std::string(strv.substr(0, c)));
        int y = std::stoi(std::string(strv.substr(c + 1, e)));
        // std::cout << x << " " << y << std::endl;
        return std::make_pair(x, y);
    }

    void read_input(const std::string &filename) {
        std::ifstream file(filename);
        std::string line;
        if (file.is_open()) {
            while (std::getline(file, line)) {
                auto a = split_line(std::string(line));
                for (int i = 0; i < a.size() - 1; i += 1) {
                    insert_range(a[i], a[i + 1]);
                }
            }
        }
        file.close();
    }
};


int solve_14_1() {
    map m;
    m.read_input("/home/antoni/dev/aoc22/day14/data.txt");
    m.fill_empty();
    m.part1();
}

int solve_14_2() {
    map m;
    m.read_input("/home/antoni/dev/aoc22/day14/data.txt");
    m.fill_2();
    m.part2();
}

void solve_14() {
    std::cout << "Day 14: " << std::endl;
    std::cout << "--------------------" << std::endl;
    std::cout << "Part 2: " << std::endl;
    solve_14_2();
    std::cout << "Part 1: " << std::endl;
    solve_14_1();
}

#endif //AOC22_DAY14_H
