/*
[122. Best Time to Buy and Sell Stock II (Medium)](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/)

@topic: Array
@topic: Dynamic Programming
@topic: Greedy

Constraints:
  - `1 <= prices.length <= 3 * 10^4`
  - `0 <= prices[i] <= 10^4`
*/

#include <vector>

using std::max;
using std::vector;

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 1, n = prices.size(); i < n; ++i) {
            profit += max(prices[i] - prices[i - 1], 0);
        }
        return profit;
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

    vector<tuple<vector<int>, int>> CASES = {
        {{7, 1, 5, 3, 6, 4}, 7},
        {{1, 2, 3, 4, 5}, 4},
        {{7, 6, 4, 3, 1}, 0},
    };

    for (auto& [prices, excepted] : CASES) {
        assert(o.maxProfit(prices) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [prices, _] : CASES) {
        for (auto i = 0; i < 100000; ++i) {
            o.maxProfit(prices);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
