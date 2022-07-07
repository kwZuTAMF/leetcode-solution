/*
[762. Prime Number of Set Bits in Binary Representation (Easy)](https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/)

@topic: Math
@topic: Bit Manipulation

Constraints:
  - `1 <= left <= right <= 10^6`
  - `0 <= right - left <= 10^4`
*/

class Solution {
   public:
    int countPrimeSetBits(int left, int right) {
        int count = 0;
        for (int i = left; i <= right; ++i)
            if ((1 << __builtin_popcount(i)) & 0b10100010100010101100)
                ++count;
        return count;
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
        {6, 10, 4},
        {10, 15, 5},
    };

    for (auto& [left, right, excepted] : CASES) {
        assert(o.countPrimeSetBits(left, right) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [left, right, _] : CASES) {
        for (int i = 0; i < 1000000000; ++i) {
            o.countPrimeSetBits(left, right);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
