#include <iostream>
#include <fstream>
#include <string>

#include "advent.hpp"
#include "day1.hpp"
using namespace std;


int main(void) {
    int a1 = p1("../inputs/1t.txt");
    int a2 = p2("../inputs/1t.txt");
    EXPECT(a1, 3);
    EXPECT(a2, 6);
    PASS();
}