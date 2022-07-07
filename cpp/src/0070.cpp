/*
[70. Climbing Stairs (Easy)](https://leetcode.com/problems/climbing-stairs/)

@topic: Math
@topic: Dynamic Programming
@topic: Memoization

Constraints:
  - `1 <= n <= 45`
*/

#include <vector>

using std::vector;

class Solution {
   public:
    int climbStairs(int n) {
        if (n <= 1) return n;
        int dp[3]{0, 1, 2};
        for (int i = 3; i <= n; ++i) {
            dp[0] = dp[1] + dp[2];
            dp[1] = dp[2];
            dp[2] = dp[0];
        }
        return dp[2];
    }

    // int climbStairs(int n) {
    //     if (n <= 1) return n;
    //     vector<int> dp(n + 1);
    //     dp[1] = 1;
    //     dp[2] = 2;
    //     for (int i = 3; i <= n; ++i) {
    //         dp[i] = dp[i - 1] + dp[i - 2];
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
        {2, 2},
        {3, 3},
    };

    for (auto &[n, excepted] : CASES) {
        assert(o.climbStairs(n) == excepted);
    }

    auto start = system_clock::now();
    for (auto &[n, _] : CASES) {
        for (auto i = 0; i < 100000; ++i) {
            o.climbStairs(n);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
