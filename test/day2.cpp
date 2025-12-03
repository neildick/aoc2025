#include "day2.hpp"
using namespace std;


int main(void) {
    //int a2 = p2("../inputs/2t.txt");
    auto ranges = parse("C:/Users/neilj/source/repos/aoc2025/inputs/2t.txt");
    int64_t a1 = p1(ranges);
    int64_t a2 = p2(ranges);
    EXPECT(a1, 1227775554);
    EXPECT(compare_id({ '1', '2', '3' }, {'3', '2', '1'}), true);
    EXPECT(valid_id("44"), false);
    EXPECT(valid_id("48"), true);
    EXPECT(valid_id("1010"), false);
    EXPECT(valid_id("446446"), false);
    EXPECT(valid_id("38593862"), true);
    EXPECT(valid_id("38593859"), false);
    PASS();
}