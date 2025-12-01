#include <iostream>
#include <fstream>
#include <string>
#include "advent.hpp"
#include "day1.hpp"

using namespace std;

int main(void) {
    int a1 = p1("../inputs/1.txt");
    int a2 = p2("../inputs/1.txt");
    cout << "p1: " << a1 << endl;
    cout << "p2: " << a2 << endl;
    return 0;
}