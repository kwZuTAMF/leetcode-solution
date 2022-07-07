/*
[96. Unique Binary Search Trees (Medium)](https://leetcode.com/problems/unique-binary-search-trees/)

@topic: Math
@topic: Dynamic Programming
@topic: Tree
@topic: Binary Search Tree
@topic: Binary Tree

Constraints:
  - `1 <= n <= 19`
*/

#include <vector>

using std::max;
using std::vector;

class Solution {
   public:
    // int numTrees(int n) {
    //     auto fact = [](int n) -> int {
    //         int x = 1;
    //         for (int i = 1; i <= n; ++i) x *= i;
    //         return x;
    //     };
    //     return fact(2 * n) / fact(n + 1) / fact(n);
    // }

    // int numTrees(int n) {
    //     auto C = 1LL;
    //     for (int i = 0; i < n; ++i) {
    //         C = C * 2 * (2 * i + 1) / (i + 2);
    //     }
    //     return C;
    // }

    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
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
        {3, 5},
        {1, 1},
    };

    for (auto &[n, excepted] : CASES) {
        assert(o.numTrees(n) == excepted);
    }

    auto start = system_clock::now();
    for (auto &[n, _] : CASES) {
        for (auto i = 0; i < 100000; ++i) {
            o.numTrees(n);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
