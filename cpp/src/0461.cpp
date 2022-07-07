/*
[461. Hamming Distance (Easy)](https://leetcode.com/problems/hamming-distance/)

@topic: Bit Manipulation

Constraints:
  - `0 <= x, y <= 2^31 - 1`
*/

#include <cstdint>

class Solution {
   public:
    // int hammingDistance(int x, int y) {
    //     int count = 0;
    //     for (uint32_t n = x ^ y; n; n &= n - 1) ++count;
    //     return count;
    // }

    int hammingDistance(int x, int y) {
        uint32_t n = x ^ y;
        n -= ((n >> 1) & 0x55555555);
        n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
        n = (n + (n >> 4)) & 0x0f0f0f0f;
        n += (n >> 8);
        n += (n >> 16);
        return n & 0x3f;
    }
};

#include <cassert>
#include <chrono>
#include <iostream>
#include <vector>

using std::tuple;
using std::vector;
using std::chrono::duration_cast;
using std::chrono::microseconds;
using std::chrono::system_clock;

int main() {
    Solution o;

    vector<tuple<int, int, int>> CASES = {
        {1, 4, 2},
        {3, 1, 1},
    };

    for (auto& [x, y, excepted] : CASES) {
        assert(o.hammingDistance(x, y) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [x, y, _] : CASES) {
        for (int i = 0; i < 100000; ++i) {
            o.hammingDistance(x, y);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
