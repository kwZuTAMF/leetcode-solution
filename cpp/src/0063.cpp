/*
[63. Unique Paths II (Medium)](https://leetcode.com/problems/unique-paths-ii/)

@topic: Array
@topic: Dynamic Programming
@topic: Matrix

Constraints:
  - `m == obstacleGrid.length`
  - `n == obstacleGrid[i].length`
  - `1 <= m, n <= 100`
  - `obstacleGrid[i][j]` is `0` or `1`.
*/

#include <vector>

using std::max;
using std::vector;

class Solution {
   public:
    // TODO: improve
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) return 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m && obstacleGrid[i][0] == 0; ++i) dp[i][0] = 1;
        for (int j = 0; j < n && obstacleGrid[0][j] == 0; ++j) dp[0][j] = 1;
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 0) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
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

    vector<tuple<vector<vector<int>>, int>> CASES = {
        {{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}}, 2},
        {{{0, 1}, {0, 0}}, 1},
    };

    for (auto &[obstacleGrid, excepted] : CASES) {
        assert(o.uniquePathsWithObstacles(obstacleGrid) == excepted);
    }

    auto start = system_clock::now();
    for (auto &[obstacleGrid, _] : CASES) {
        for (auto i = 0; i < 100000; ++i) {
            o.uniquePathsWithObstacles(obstacleGrid);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
