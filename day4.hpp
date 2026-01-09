#include "advent.hpp"

int p1(const char* path) {
	auto adv = advent(path);
	int count = 0;
	for (int y = 0; y < adv.cmap.height; y++) {
		for (int x = 0; x < adv.cmap.width; x++) {
			if (adv.cmap.get(make_pair(x, y)) == '.') continue;
			auto neighbours = adv.cmap.neighbours(make_pair(x, y));
			auto point_count = count_if(neighbours.begin(), 
										neighbours.end(), 
										[&adv](pair<int,int> &p){return adv.cmap.get(p) == '@';});
			if (point_count < 4) count++;
		}
	}
	return count;
}

int p2(const char* path) {
	auto adv = advent(path);
	int total_removed = 0;
	while (true) {
		vector<pair<int, int>> to_remove;
		for (int y = 0; y < adv.cmap.height; y++) {
			for (int x = 0; x < adv.cmap.width; x++) {
				if (adv.cmap.get(make_pair(x, y)) == '.') continue;
				auto neighbours = adv.cmap.neighbours(make_pair(x, y));
				auto point_count = count_if(neighbours.begin(), 
										    neighbours.end(), 
										    [&adv](pair<int,int> &p){return adv.cmap.get(p) == '@';});
				if (point_count < 4) {
					total_removed++;
					to_remove.push_back(make_pair(x, y));
				}
			}
		}
		if (to_remove.empty()) break;
		for (auto const& p : to_remove) {
			adv.cmap.set(p, '.');
		}
	}
	return total_removed;
}