/*
[231. Power of Two (Easy)](https://leetcode.com/problems/power-of-two/)

@topic: Math
@topic: Bit Manipulation
@topic: Recursion

Constraints:
  - `-2^31 <= n <= 2^31 - 1`
*/

class Solution {
   public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }

    // bool isPowerOfTwo(int n) {
    //     return n > 0 && (n & -n) == n;
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
        {1, true},
        {16, true},
        {3, false},
    };

    for (auto& [n, excepted] : CASES) {
        assert(o.isPowerOfTwo(n) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [n, _] : CASES) {
        for (int i = 0; i < 100000; ++i) {
            o.isPowerOfTwo(n);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
