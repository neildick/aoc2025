#pragma once
#include "advent.hpp"
#include <set>
#include <expected>
#include <system_error>
using range = pair<int64_t, int64_t>;

auto in_range(const set<range> &ranges, int64_t id) -> expected<range, error_code> 
{
    bool found = false;
    for (auto const &r : ranges) {
        if (id >= r.first && id <= r.second) {
            return r;
        }
    }
    return unexpected(make_error_code(errc::invalid_argument));
}

auto p2(const char *path) -> int64_t
{
    ifstream f(path);

    if (!f.is_open()) {cout << "file not found \n"; exit(1);}
    string s;
    bool done = false;
    set<range> ranges;
    int64_t count = 0;

    while(getline(f, s)) {
        
        if (s.empty()) {
            done = true;
            continue;
        }
        if (!done) {
            auto range = split(s, "-");
            assert (range.size() == 2);
            int64_t start = stoll(range[0]);
            int64_t finish = stoll(range[1]);
            auto r = in_range(ranges, start);
            if (r) {
                cout << "matched range " << r.value().first << " " << r.value().second << endl;
            }
            ranges.insert(make_pair(start,finish));


        } else {
            int64_t id = stoll(s);
            if (in_range(ranges, id)) count++;
        }
    }
    return count;
}

auto p1(const char *path) -> int64_t 
{
    ifstream f(path);

    if (!f.is_open()) {cout << "file not found \n"; exit(1);}
    string s;
    bool done = false;
    set<range> ranges;
    int64_t count = 0;

    while(getline(f, s)) {
        
        if (s.empty()) {
            done = true;
            continue;
        }
        if (!done) {
            auto range = split(s, "-");
            assert (range.size() == 2);
            int64_t start = stoll(range[0]);
            int64_t finish = stoll(range[1]);
            ranges.insert(make_pair(start,finish));

        } else {
            int64_t id = stoll(s);
            if (in_range(ranges, id)) count++;
        }
    }
    return count;
}