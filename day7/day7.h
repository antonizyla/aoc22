//
// Created by antoni on 12/7/22.
//

#ifndef AOC22_DAY7_H
#define AOC22_DAY7_H


#include <vector>
#include <algorithm>

// https://stackoverflow.com/questions/410980/include-a-text-file-in-a-c-program-as-a-char
const std::string_view input = {
#include "/home/antoni/dev/aoc22/day7/data.txt"
};

int calc_dir_sizes(std::string_view &strv, std::vector<int> &sizes) {
    int curr_size = 0;
    while (!strv.empty()) {
        if (strv[2] == 'c') { // check for cd
            bool back = strv[5] == '.';
            strv.remove_prefix(1 + strv.find('\n'));
            if (back) {
                return curr_size;
            } else {
                // go into next directory with trimmed input string
                int const size = calc_dir_sizes(strv, sizes);
                sizes.push_back(size);
                curr_size += size;
            }
        } else if (strv[2] == 'l') {// check for ls
            strv.remove_prefix(5);   // skip '$ ls\n'
            while (!strv.empty() && strv[0] != '$') {
                if (strv[0] != 'd') {
                    curr_size += std::atoi(strv.data());
                }
                strv.remove_prefix(1 + strv.find('\n'));
            }
        }
    }
    return curr_size;
}

void solve_7() {
    std::vector<int> dir_sizes;
    std::string_view input_c = input;
    int used_space = calc_dir_sizes(input_c, dir_sizes);

    uint under100k = 0;
    std::ranges::sort(dir_sizes);
    for (auto &size: dir_sizes) {
        if (size > 100000) {
            break;
        }
        under100k += size;
    }
    std::cout << "Part 1: " << under100k << std::endl;

    int missing = (30'000'000) - (70'000'000 - used_space);
    std::cout << "Part 2 : " << *std::ranges::upper_bound(dir_sizes, missing) << std::endl;
}
#endif //AOC22_DAY7_H
