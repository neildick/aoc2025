#pragma once
#include "advent.hpp"

inline int
ctoi(const char c) {
	return c - '0';
}

int get_largest(const string& bank) {
	int best = 0;
	for (int i = 0; i < bank.length(); i++)
		if (bank[i] > bank[best]) best = i;

	return best;
}

inline
int min(int a, int b) {
	return a < b ? a : b;
}

int64_t get_best_2(const string& bank) {
	int64_t sum = 0;
	size_t offset = 0;
	for (int i = 0; i < 12; i++) {
		size_t best = get_largest(bank.substr(offset, bank.length() - (11 - i) - offset));
		sum += pow(10, (12 - i - 1)) * ctoi(bank[best + offset]);
		offset += best + 1;
	}

	return sum;
}

int get_best(const string& bank) {
	size_t left_best = 0;
	size_t right_best = bank.length() - 1;

	for (size_t left = 0; left < bank.length()-1; left++) {
		if (bank[left] > bank[left_best]) {
			left_best = left;
		}
	}

	for (size_t right = left_best+1; right < bank.length(); right++) {
		if (bank[right] > bank[right_best]) {
			right_best = right;
		}
	}
	return ctoi(bank[left_best]) * 10 + ctoi(bank[right_best]);
}

int64_t p1(const char *path) {
	auto f = ifstream(path);
	if (!f.is_open()) { cout << "file not found \n"; exit(-1); }
	int64_t sum = 0;
	string s;
	while (getline(f, s)) {
		int64_t best = get_best(s);
		sum += best;
	}
	return sum;
}
int64_t p2(const char* path) {
	auto f = ifstream(path);
	if (!f.is_open()) { cout << "file not found \n"; exit(-1); }
	int64_t sum = 0;
	string s;
	while (getline(f, s)) {
		int64_t best = get_best_2(s);
		sum += best;
	}
	return sum;
}