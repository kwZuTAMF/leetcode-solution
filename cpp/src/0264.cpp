/*
[264. Ugly Number II (Medium)](https://leetcode.com/problems/ugly-number-ii/)

@topic: Hash Table
@topic: Math
@topic: Dynamic Programming
@topic: Heap (Priority Queue)

Constraints:
  - `1 <= n <= 1690`
*/

#include <vector>

using std::min;
using std::vector;

class Solution {
   public:
    int nthUglyNumber(int n) {
        vector<int> dp(n, 1);
        int i2 = 0, i3 = 0, i5 = 0;
        for (int i = 1; i < n; ++i) {
            int n2 = dp[i2] * 2, n3 = dp[i3] * 3, n5 = dp[i5] * 5;
            int next = min(n2, min(n3, n5));
            if (next == n2) ++i2;
            if (next == n3) ++i3;
            if (next == n5) ++i5;
            dp[i] = next;
        }
        return dp[n - 1];
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

    vector<tuple<int, int>> CASES = {
        {10, 12},
        {1, 1},
    };

    for (auto& [n, excepted] : CASES) {
        assert(o.nthUglyNumber(n) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [n, _] : CASES) {
        for (auto i = 0; i < 100000; ++i) {
            o.nthUglyNumber(n);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
