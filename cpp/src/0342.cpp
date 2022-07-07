/*
[342. Power of Four (Easy)](https://leetcode.com/problems/power-of-four/)

@topic: Math
@topic: Bit Manipulation
@topic: Recursion

Constraints:
  - `-2^31 <= n <= 2^31 - 1`
*/

class Solution {
   public:
    bool isPowerOfFour(int n) {
        return n > 0 && (n & (n - 1)) == 0 && (n & 0x55555555) == n;
    }

    // bool isPowerOfFour(int n) {
    //     return n > 0 && (n & (n - 1)) == 0 && n % 3 == 1;
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
        {16, true},
        {5, false},
        {1, true},
    };

    for (auto& [n, excepted] : CASES) {
        assert(o.isPowerOfFour(n) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [n, _] : CASES) {
        for (int i = 0; i < 100000; ++i) {
            o.isPowerOfFour(n);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
