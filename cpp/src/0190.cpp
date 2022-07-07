/*
[190. Reverse Bits (Easy)](https://leetcode.com/problems/reverse-bits/)

@topic: Divide and Conquer
@topic: Bit Manipulation

Constraints:
  - The input must be a **binary string** of length `32`
*/

#include <cstdint>

class Solution {
   public:
    // uint32_t reverseBits(uint32_t n) {
    //     uint32_t rev = 0;
    //     for (uint32_t i = 0; i < 32 && n; ++i) {
    //         rev |= (n & 1) << (31 - i);
    //         n >>= 1;
    //     }
    //     return rev;
    // }

    uint32_t reverseBits(uint32_t n) {
        n = ((n & 0x55555555) << 1) | ((n >> 1) & 0x55555555);
        n = ((n & 0x33333333) << 2) | ((n >> 2) & 0x33333333);
        n = ((n & 0x0f0f0f0f) << 4) | ((n >> 4) & 0x0f0f0f0f);
        n = ((n & 0x00ff00ff) << 8) | ((n >> 8) & 0x00ff00ff);
        return (n << 16 | n >> 16);
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

    vector<tuple<uint32_t, uint32_t>> CASES = {
        {0b00000010100101000001111010011100, 0b00111001011110000010100101000000},
        {0b11111111111111111111111111111101, 0b10111111111111111111111111111111},
    };

    for (auto& [n, excepted] : CASES) {
        assert(o.reverseBits(n) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [n, _] : CASES) {
        for (int i = 0; i < 100000; ++i) {
            o.reverseBits(n);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
