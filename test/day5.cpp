#include "day5.hpp"

int main(void) {

    auto a1 = p1("../inputs/5t.txt");
    auto a2 = p2("../inputs/5t.txt");
    EXPECT(a1, 3);
    EXPECT(a2, 14);
    PASS();
}