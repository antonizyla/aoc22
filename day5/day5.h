//
// Created by antoni on 12/5/22.
//

#ifndef AOC22_DAY5_H
#define AOC22_DAY5_H

#include <string>
#include <stack>
#include <vector>
#include <fstream>
#include <list>
#include <unordered_map>
#include <iostream>

class instruction {
public:
    instruction(int _count, int _from, int _to);

    void print() const;

public:
    int count;
    int from;
    int to;
};

instruction::instruction(int _count, int _from, int _to) {
    count = _count;
    from = _from;
    to = _to;
}

void instruction::print() const {
    std::cout << "count: " << count << " from: " << from << " to: " << to << std::endl;
}

instruction parse_instruction(const std::string &line) {
    // line looks like : move 1 from 1 to 2
    std::vector<std::string> tokens;
    tokens.reserve(5);
    size_t start;
    size_t end = 0;
    while ((start = line.find_first_not_of(' ', end)) != std::string::npos) {
        end = line.find(' ', start);
        tokens.push_back(line.substr(start, end - start));
    }
    instruction inst(std::stoi(tokens[1]), std::stoi(tokens[3]), std::stoi(tokens[5]));
    return inst;
}

std::unordered_map<int, std::list<char>> get_intitial_stacks() {
    std::unordered_map<int, std::list<char>> stacks;
    stacks[1] = std::list<char>({'F', 'L', 'M', 'W'});
    stacks[2] = std::list<char>({'F', 'M', 'V', 'Z', 'B'});
    stacks[3] = std::list<char>({'Q', 'L', 'S', 'R', 'V', 'H'});
    stacks[4] = std::list<char>({'J', 'T', 'M', 'P', 'Q', 'V', 'S', 'F'});
    stacks[5] = std::list<char>({'W', 'S', 'L'});
    stacks[6] = std::list<char>({'W', 'J', 'R', 'M', 'P', 'V', 'F'});
    stacks[7] = std::list<char>({'F', 'R', 'N', 'P', 'C', 'Q', 'J'});
    stacks[8] = std::list<char>({'B', 'R', 'W', 'Z', 'S', 'P', 'H', 'V'});
    stacks[9] = std::list<char>({'W', 'Z', 'H', 'G', 'C', 'J', 'M', 'B'});
    return stacks;
}

void solve_5() {
    std::ifstream file("/home/antoni/dev/aoc22/day5/data.txt");

    auto stacks = get_intitial_stacks();

    // read instructions into vector
    std::vector<instruction> instructions;
    //instructions.reserve(400);
    std::string line;
    if (file.is_open()) {
        while (std::getline(file, line)) {
            instructions.push_back(parse_instruction(line));
        }
    }

    for (auto inst: instructions) {
        for (int i = 0; i < inst.count; i++) {
            char moved = stacks[inst.from].front();
            stacks[inst.from].pop_front();
            stacks[inst.to].push_front(moved);
        }
    }

    std::cout << "Part 1: Top Items: ";
    for (int i = 1; i <= stacks.size(); i++) {
        std::cout << stacks[i].front();
    }
    std::cout << std::endl;

    // reset stacks for part 2
    stacks = get_intitial_stacks();
    for (auto inst: instructions) {
        std::list<char> buffer;
        for (int i = 0; i < inst.count; i++) {
            char moved = stacks[inst.from].front();
            stacks[inst.from].pop_front();
            buffer.push_front(moved);
        }
        for (auto item: buffer) {
            stacks[inst.to].push_front(item);
        }
    }

    std::cout << "Part 2: Top Items: ";
    for (int i = 1; i <= stacks.size(); i++) {
        std::cout << stacks[i].front();
    }
    std::cout << std::endl;
}

#endif //AOC22_DAY5_H
