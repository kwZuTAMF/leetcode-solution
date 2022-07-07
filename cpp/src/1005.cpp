/*
[1005. Maximize Sum Of Array After K Negations (Easy)](https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/)

@topic: Array
@topic: Greedy
@topic: Sorting

Constraints:
  - `1 <= nums.length <= 10^4`
  - `-100 <= nums[i] <= 100`
  - `1 <= k <= 10^4`
*/

#include <algorithm>
#include <numeric>
#include <vector>

using std::abs;
using std::accumulate;
using std::sort;
using std::vector;

class Solution {
   public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), [](int a, int b) { return abs(a) < abs(b); });
        for (int i = nums.size() - 1; i >= 0 && k; --i) {
            if (nums[i] < 0) {
                nums[i] *= -1;
                --k;
            }
        }
        if (k & 1) {
            nums[0] *= -1;
        }
        return accumulate(nums.begin(), nums.end(), 0);
    }
};

#include <cassert>
#include <chrono>
#include <iostream>
#include <vector>

using std::tuple;
using std::vector;
using std::chrono::duration_cast;
using std::chrono::microseconds;
using std::chrono::system_clock;

int main() {
    Solution o;

    vector<tuple<vector<int>, int, int>> CASES = {
        {{4, 2, 3}, 1, 5},
        {{3, -1, 0, 2}, 3, 6},
        {{2, -3, -1, 5, -4}, 2, 13},
    };

    for (auto& [nums, k, excepted] : CASES) {
        assert(o.largestSumAfterKNegations(nums, k) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [nums, k, _] : CASES) {
        for (int i = 0; i < 100000; ++i) {
            o.largestSumAfterKNegations(nums, k);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
