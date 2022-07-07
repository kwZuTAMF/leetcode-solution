/*
[509. Fibonacci Number (Easy)](https://leetcode.com/problems/fibonacci-number/)

@topic: Math
@topic: Dynamic Programming
@topic: Recursion
@topic: Memoization

Constraints:
  - `0 <= n <= 30`
*/

#include <vector>

using std::vector;

class Solution {
   public:
    int fib(int n) {
        if (n <= 1) return n;
        int dp[3]{0, 1, 1};
        for (int i = 2; i <= n; ++i) {
            dp[2] = dp[1] + dp[0];
            dp[0] = dp[1];
            dp[1] = dp[2];
        }
        return dp[2];
    }

    // int fib(int n) {
    //     if (n <= 1) return n;
    //     vector<int> dp(n + 1);
    //     dp[0] = 0;
    //     dp[1] = 1;
    //     for (int i = 2; i <= n; ++i) {
    //         dp[i] = dp[i - 1] + dp[i - 2];
    //     }
    //     return dp[n];
    // }

    // int fib(int n, int a = 0, int b = 1) {
    //     return n == 0 ? a : fib(n - 1, b, a + b);
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
        {3, 2},
        {4, 3},
    };

    for (auto &[n, excepted] : CASES) {
        assert(o.fib(n) == excepted);
    }

    auto start = system_clock::now();
    for (auto &[n, _] : CASES) {
        for (auto i = 0; i < 100000; ++i) {
            o.fib(n);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
