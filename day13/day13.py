from functools import cmp_to_key

import os
import sys
import itertools


# -1 for less than, 0 for equal and 1 for greater
def compare(left, right):
    if left is None:
        return -1
    if right is None:
        return 1
    if isinstance(left, int) and isinstance(right, int):
        if left < right:
            return -1
        elif left > right:
            return 1
        return 0
    elif isinstance(left, list) and isinstance(right, list):
        for l2, r2 in itertools.zip_longest(left, right):
            res = compare(l2, r2)
            if res != 0:
                return res
        return 0
    else:
        l = [left] if isinstance(left, int) else left
        r = [right] if isinstance(right, int) else right
        return compare(l, r)


def read_file(filename: str):
    lines = open(filename, 'r').read().split("\n")
    result = []
    for line in lines:
        if line != "":
            result.append(line)
    return [eval(term) for term in result]
def part_1(data):
    return sum(((i + 1) // 2 + 1) for i in range(0, len(data), 2) if compare(data[i], data[i + 1]) < 0)

def part_2(data):
    sorted_data = sorted([*data, [[2]], [[6]]], key=cmp_to_key(compare))
    return (sorted_data.index([[2]]) + 1) * (sorted_data.index([[6]]) + 1)

data = read_file("/home/antoni/dev/aoc22/day13/data.txt")
print(part_1(data))
print(part_2(data))