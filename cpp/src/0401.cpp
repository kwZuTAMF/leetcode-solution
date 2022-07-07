/*
[401. Binary Watch (Easy)](https://leetcode.com/problems/binary-watch/)

@topic: Backtracking
@topic: Bit Manipulation

Constraints:
  - `0 <= turnedOn <= 10`
*/

#include <string>
#include <vector>

using std::string;
using std::to_string;
using std::vector;

class Solution {
   public:
    vector<string> readBinaryWatch(int turnedOn) {
        if (turnedOn >= 9) return {};
        if (turnedOn == 0) return {"0:00"};
        vector<string> res;
        int counts[60];
        for (int i = 0; i < 60; ++i) counts[i] = __builtin_popcount(i);
        for (int h = 0; h < 12; ++h) {
            for (int m = 0; m < 60; ++m) {
                if (counts[h] + counts[m] == turnedOn) {
                    res.emplace_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
                }
            }
        }
        return res;
    }
};

#include <cassert>
#include <chrono>
#include <iostream>

using std::tuple;
using std::chrono::duration_cast;
using std::chrono::microseconds;
using std::chrono::system_clock;

int main() {
    Solution o;

    vector<tuple<int, vector<string>>> CASES = {
        {1, {"0:01", "0:02", "0:04", "0:08", "0:16", "0:32", "1:00", "2:00", "4:00", "8:00"}},
        {9, {}},
    };

    for (auto& [turnedOn, excepted] : CASES) {
        assert(o.readBinaryWatch(turnedOn) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [turnedOn, _] : CASES) {
        for (int i = 0; i < 100000; ++i) {
            o.readBinaryWatch(turnedOn);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
