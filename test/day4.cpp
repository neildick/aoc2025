#include "day4.hpp"

int main() {
	auto a1 = p1("../inputs/4t.txt");
	auto a2 = p2("../inputs/4t.txt");

	EXPECT(a1, 13);
	EXPECT(a2, 43);

	return 0;
}