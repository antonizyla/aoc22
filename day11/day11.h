//
// Created by antoni on 12/11/22.
//

#ifndef AOC22_DAY11_H
#define AOC22_DAY11_H


#include <list>
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

enum operations {
    add, multiply, square
};

struct monkey {
    std::list<std::uint64_t> items;
    int operand{};
    operations op{};
    int div_by{};
    int true_monkey{};
    int false_monkey{};
    int thrown_count = 0;
};

void print_monkey(const monkey &m) {
    std::cout << "Items: " << std::endl;
    for (auto i: m.items) {
        std::cout << i << " ";
    }
    std::cout << "\nOperand: " << m.operand << std::endl;
    std::cout << "Op_addition: " << m.op << std::endl;
    std::cout << "Div_by: " << m.div_by << std::endl;
    std::cout << "True_monkey: " << m.true_monkey << std::endl;
    std::cout << "False_monkey: " << m.false_monkey << std::endl;
    std::cout << std::endl;
}

std::vector<std::string> split(const std::string &s) {
    std::string token;
    std::vector<std::string> tokens;
    std::stringstream ss(s);
    while (ss >> token) {
        tokens.push_back(token);
    }
    return tokens;
}

std::vector<monkey> read_input(const std::string &file) {
    std::vector<monkey> ret;
    std::ifstream fs(file);

    std::string line;
    while (std::getline(fs, line)) {
        auto tokens = split(line);
        if (!tokens.empty()) {
            if (tokens[0] == "Monkey") {
                ret.emplace_back();
            } else if (tokens[0] == "Starting") {
                for (int i = 2; i < tokens.size(); ++i) {
                    ret.back().items.push_back(std::stoi(tokens[i]));
                }
            } else if (tokens[0] == "Operation:") {
                if (tokens[5] == "old") {
                    ret.back().op = square;
                    ret.back().operand = 0;
                } else if (tokens[4] == "*") {
                    ret.back().op = multiply;
                    ret.back().operand = std::stoi(tokens[5]);
                } else if (tokens[4] == "+") {
                    ret.back().op = add;
                    ret.back().operand = std::stoi(tokens[5]);
                }
            } else if (tokens[0] == "Test:") {
                ret.back().div_by = std::stoi(tokens[3]);
            } else if (tokens[1] == "true:") {
                ret.back().true_monkey = std::stoi(tokens[5]);
            } else if (tokens[1] == "false:") {
                ret.back().false_monkey = std::stoi(tokens[5]);
            }
        }
    }
    return ret;
}

uint64_t monkey_business(auto &monkeys, int rounds, bool part1) {

    int prod = 1;
    for (monkey const &m: monkeys) {
        prod *= m.div_by;
    }

    for (int round = 1; round <= rounds; ++round) {
        for (auto &monkey: monkeys) {
            for (auto it = monkey.items.begin(); it != monkey.items.end(); it = monkey.items.erase(it)) {
                monkey.thrown_count++;
                auto &item = *it;
                if (monkey.op == add) {
                    item += monkey.operand;
                } else if (monkey.op == multiply) {
                    item *= monkey.operand;
                } else if (monkey.op == square) {
                    item *= item;
                }
                if (part1) {
                    item /= 3;
                }
                int next = (item % monkey.div_by) == 0 ? monkey.true_monkey : monkey.false_monkey;
                monkeys[next].items.push_back(item % prod);
            }
        }
    }
    // monkey business = product of two highest thrown counts
    uint64_t max1 = 0;
    uint64_t max2 = 0;
    for (auto const &m: monkeys) {
        if (m.thrown_count > max1) {
            max2 = max1;
            max1 = m.thrown_count;
        } else if (m.thrown_count > max2) {
            max2 = m.thrown_count;
        }
    }
    return max1 * max2;
}

void solve_11() {
    auto input = read_input("/home/antoni/dev/aoc22/day11/data.txt");
    std::cout << "Part 1: " << std::endl;
    std::cout << monkey_business(input, 20, true) << std::endl;
    std::cout << "---------------------------" << std::endl;
    std::cout << "Part 2: " << std::endl;
    auto input2 = read_input("/home/antoni/dev/aoc22/day11/data.txt");
    std::cout << monkey_business(input2, 10000, false) << std::endl;

}

#endif //AOC22_DAY11_H
