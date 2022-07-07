/*
[62. Unique Paths (Medium)](https://leetcode.com/problems/unique-paths/)

@topic: Math
@topic: Dynamic Programming
@topic: Combinatorics

Constraints:
  - `1 <= m, n <= 100`
*/

#include <vector>

using std::max;
using std::vector;

class Solution {
   public:
    // TODO: improve
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) return 1;
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = 0; i < m; ++i) dp[i][0] = 1;
        for (int j = 0; j < n; ++j) dp[0][j] = 1;
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
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

    vector<tuple<int, int, int>> CASES = {
        {3, 7, 28},
        {3, 2, 3},
    };

    for (auto &[m, n, excepted] : CASES) {
        assert(o.uniquePaths(m, n) == excepted);
    }

    auto start = system_clock::now();
    for (auto &[m, n, _] : CASES) {
        for (auto i = 0; i < 100000; ++i) {
            o.uniquePaths(m, n);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
