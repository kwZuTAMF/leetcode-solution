/*
[693. Binary Number with Alternating Bits (Easy)](https://leetcode.com/problems/binary-number-with-alternating-bits/)

@topic: Bit Manipulation

Constraints:
  - `1 <= n <= 2^31 - 1`
*/

class Solution {
   public:
    bool hasAlternatingBits(int n) {
        return (n & 0b0101010101010101010101010101010) == 0 ||
               (n & 0b1010101010101010101010101010101) == n;
    }

    // bool hasAlternatingBits(int n) {
    //     unsigned x = n ^ (n >> 1);
    //     return (x & (x + 1)) == 0;
    // }
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

    vector<tuple<int, bool>> CASES = {
        {5, true},
        {7, false},
        {11, false},
    };

    for (auto& [n, excepted] : CASES) {
        assert(o.hasAlternatingBits(n) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [n, _] : CASES) {
        for (int i = 0; i < 100000; ++i) {
            o.hasAlternatingBits(n);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
