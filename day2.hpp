#pragma once
#include "advent.hpp"

using puzzle = vector<pair<string, string>>;

bool compare_id(const vector<char>& a, const vector<char>& b) {
    assert(a.size() == b.size());
    return equal(a.begin(), a.end(), b.rbegin());
}

bool valid_id(const string id) {
    size_t head = 0;
    size_t tail = id.length() - 1;
    vector<char> forwards;
    vector<char> backwards;
    if ((tail & 0x01) == 0) return true;
    while (head < tail) {
        forwards.push_back(id[head]);
        backwards.push_back(id[tail]);
        head++; tail--;
    }
    return !compare_id(forwards, backwards);
}

puzzle parse(const char* path) {
    puzzle res;
    auto f = ifstream(path);
    if (!f.is_open()) { cout << "file not found!\n"; exit(-1); }
    string s;
    getline(f, s);
    auto ranges = split(s, ",");
    for (auto const& range : ranges) {
        auto t = split(range, "-");
        assert(t.size() == 2);
        res.push_back(make_pair(t[0], t[1]));
    }
    return res;
}

int64_t p1(puzzle& p) {
    int64_t sum = 0;
    for (auto const &range : p) {
        auto left = stoll(range.first);
        auto right = stoll(range.second);
        for (auto i = left; i <= right; i++) {
            auto id = to_string(i);
            if (!valid_id(id)) {
                sum += i;
            }
        }
    }
    return sum;
}

bool valid_id2(const string id) {
    int size = 1;

    while (size < id.size() - 1) {
        auto s = id.substr(0, size);
        auto next = id.substr(size, 2 * size);
    }
    return false;
}


int64_t p2(puzzle& p) {
    int64_t sum = 0;
    for (auto const& range : p) {
        auto left = stoll(range.first);
        auto right = stoll(range.second);
        for (auto i = left; i <= right; i++) {
            auto id = to_string(i);
            if (!valid_id2(id)) {
                sum += i;
            }
        }
    }
    return sum;
}