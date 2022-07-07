/*
[191. Number of 1 Bits (Easy)](https://leetcode.com/problems/number-of-1-bits/)

@topic: Divide and Conquer
@topic: Bit Manipulation

Constraints:
  - The input must be a **binary string** of length `32`.
*/

#include <cstdint>

class Solution {
   public:
    // int hammingWeight(uint32_t n) {
    //     int count = 0;
    //     for (; n; n &= n - 1) ++count;
    //     return count;
    // }

    int hammingWeight(uint32_t n) {
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

    vector<tuple<uint32_t, int>> CASES = {
        {0b00000000000000000000000000001011, 3},
        {0b00000000000000000000000010000000, 1},
        {0b11111111111111111111111111111101, 31},
    };

    for (auto& [n, excepted] : CASES) {
        assert(o.hammingWeight(n) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [n, _] : CASES) {
        for (int i = 0; i < 1000000000; ++i) {
            o.hammingWeight(n);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
