#pragma once
#include "advent.hpp"


int p1(const char *path) {
    auto f = ifstream(path);
    if (!f) {cout << "file not found!\n"; return -1;}

    char dir;
    int val;
    int pos = 50;
    int sum = 0;
    while (f) {
        f >> dir;
        f >> val;
        if (dir == 'L') {
            val = -val;
        }
        pos += val;
        pos = mod(pos, 100);
        if (pos == 0)
            sum++;

    }
    return sum;
}

int p2(const char *path) {
    auto f = ifstream(path);
    if (!f) {cout << "file not found!\n"; return -1;}

    char dir;
    int val;
    int pos = 50;
    int sum = 0;
    int extra = 0;
    string s;
    while (getline(f, s)) {
        dir = s[0];
        val = stol(s.substr(1));
        //cout << "pos " << pos << " extra " << extra << " sum " << sum << " val " << val << endl;
        extra += val / 100;
        val = mod(val, 100);
        if (dir == 'L') {
            if ((val > pos) && (pos != 0)) {
                extra += 1;
            }
            val = -val;
        } else {
            if (pos + val > 100)
                extra += 1;
        }

        pos += val;
        pos = mod(pos, 100);
        if (pos == 0)
            sum++;

    }
    return sum+extra;
}
