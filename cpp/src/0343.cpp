/*
[343. Integer Break (Medium)](https://leetcode.com/problems/integer-break/)

@topic: Math
@topic: Dynamic Programming

Constraints:
  - `2 <= n <= 58`
*/

#include <vector>

using std::max;
using std::vector;

class Solution {
   public:
    int integerBreak(int n) {
        switch (n) {
            case 2:
                return 1;
            case 3:
                return 2;
            case 4:
                return 4;
            default: {
                int i = 1;
                for (; n > 4; n -= 3) i *= 3;
                return i *= n;
            }
        }
    }

    // int integerBreak(int n) {
    //     if (n < 4) return n - 1;
    //     vector<int> dp(n + 1);
    //     dp[2] = 1;
    //     for (int i = 3; i <= n; ++i) {
    //         dp[i] = max(max(2 * (i - 2), 2 * dp[i - 2]), max(3 * (i - 3), 3 * dp[i - 3]));
    //     }
    //     return dp[n];
    // }

    // int integerBreak(int n) {
    //     if (n < 4) return n - 1;
    //     vector<int> dp(n + 1);
    //     dp[2] = 1;
    //     for (int i = 3; i <= n; ++i) {
    //         for (int j = 1; j < i - 1; ++j) {
    //             dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
    //         }
    //     }
    //     return dp[n];
    // }
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
        {2, 1},
        {10, 36},
    };

    for (auto &[n, excepted] : CASES) {
        assert(o.integerBreak(n) == excepted);
    }

    auto start = system_clock::now();
    for (auto &[n, _] : CASES) {
        for (auto i = 0; i < 100000; ++i) {
            o.integerBreak(n);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
