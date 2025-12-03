#include <iostream>
#include <fstream>
#include <string>
#include "day2.hpp"


int main(void) {
    auto ranges = parse("C:/Users/neilj/source/repos/aoc2025/inputs/2.txt");
    int64_t a1 = p1(ranges);

    cout << "P1: " << a1 << endl;
    return 0;
}