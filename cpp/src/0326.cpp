/*
[326. Power of Three (Easy)](https://leetcode.com/problems/power-of-three/)

@topic: Math
@topic: Recursion

Constraints:
  - `-2^31 <= n <= 2^31 - 1`
*/

#include <unordered_set>

class Solution {
   public:
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;
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

    vector<tuple<int, bool>> CASES = {
        {27, true},
        {0, false},
        {9, true},
    };

    for (auto& [n, excepted] : CASES) {
        assert(o.isPowerOfThree(n) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [n, _] : CASES) {
        for (int i = 0; i < 100000; ++i) {
            o.isPowerOfThree(n);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
