#include "day3.hpp"

int main(void) {
	EXPECT(get_best("987654321111111"), 98);
	EXPECT(get_best("811111111111119"), 89);
	EXPECT(get_best("234234234234278"), 78);
	EXPECT(get_best("818181911112111"), 92);
	EXPECT(get_best("111111111111192"), 92);

	EXPECT(get_best_2("987654321111111"), 987654321111);
	EXPECT(get_best_2("818181911112111"), 888911112111);

	int64_t a1 = p1("../../../inputs/3t.txt");
	int64_t a2 = p2("../../../inputs/3t.txt");
	cout << "ND: a1 is " << a1 << endl;
	cout << "ND: a2 is " << a2 << endl;
	EXPECT(a1, 357);
	EXPECT(a2, 3121910778619);

	PASS();
}