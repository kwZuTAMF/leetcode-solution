/*
[867. Transpose Matrix (Easy)](https://leetcode.com/problems/transpose-matrix/)

@topic: Array
@topic: Matrix
@topic: Simulation

Constraints:
  - `m == matrix.length`
  - `n == matrix[i].length`
  - `1 <= m, n <= 1000`
  - `1 <= m * n <= 10^5`
  - `-10^9 <= matrix[i][j] <= 10^9`
*/

#include <vector>

using std::max;
using std::vector;

class Solution {
   public:
    // vector<vector<int>> transpose(vector<vector<int>>& matrix) {
    //     int m = matrix.size();
    //     int n = matrix[0].size();
    //     vector<vector<int>> transposed(n, vector<int>(m));
    //     for (int i = 0; i < m; ++i) {
    //         for (int j = 0; j < n; ++j) {
    //             transposed[j][i] = matrix[i][j];
    //         }
    //     }
    //     return transposed;
    // }

    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> transposed(n, vector<int>(m));
        for (int i = 0; i < m * n; ++i) {
            transposed[i / m][i % m] = matrix[i % m][i / m];
        }
        return transposed;
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

    vector<tuple<vector<vector<int>>, vector<vector<int>>>> CASES = {
        {{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, {{1, 4, 7}, {2, 5, 8}, {3, 6, 9}}},
        {{{1, 2, 3}, {4, 5, 6}}, {{1, 4}, {2, 5}, {3, 6}}},
    };

    for (auto& [matrix, excepted] : CASES) {
        assert(o.transpose(matrix) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [matrix, _] : CASES) {
        for (auto i = 0; i < 1000; ++i) {
            o.transpose(matrix);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
