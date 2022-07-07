/*
[746. Min Cost Climbing Stairs (Easy)](https://leetcode.com/problems/min-cost-climbing-stairs/)

@topic: Array
@topic: Dynamic Programming

Constraints:
  - `2 <= cost.length <= 1000`
  - `0 <= cost[i] <= 999`
*/

#include <vector>

using std::min;
using std::vector;

class Solution {
   public:
    int minCostClimbingStairs(vector<int> &cost) {
        int dp[3]{};
        for (int i = 2, n = cost.size(); i <= n; ++i) {
            dp[2] = min(dp[1] + cost[i - 1], dp[0] + cost[i - 2]);
            dp[0] = dp[1];
            dp[1] = dp[2];
        }
        return dp[2];
    }

    // int minCostClimbingStairs(vector<int> &cost) {
    //     int n = cost.size();
    //     vector<int> dp(n + 1);
    //     for (int i = 2; i <= n; ++i) {
    //         dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
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

    vector<tuple<vector<int>, int>> CASES = {
        {{10, 15, 20}, 15},
        {{1, 100, 1, 1, 1, 100, 1, 1, 100, 1}, 6},
    };

    for (auto &[cost, excepted] : CASES) {
        assert(o.minCostClimbingStairs(cost) == excepted);
    }

    auto start = system_clock::now();
    for (auto &[cost, _] : CASES) {
        for (auto i = 0; i < 100000; ++i) {
            o.minCostClimbingStairs(cost);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
