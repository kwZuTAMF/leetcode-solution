/*
[376. Wiggle Subsequence (Medium)](https://leetcode.com/problems/wiggle-subsequence/)

@topic: Array
@topic: Dynamic Programming
@topic: Greedy

Constraints:
  - `1 <= nums.length <= 1000`
  - `0 <= nums[i] <= 1000`
*/

#include <algorithm>
#include <vector>

using std::max;
using std::sort;
using std::vector;

class Solution {
   public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return n;
        int k = 1;
        int pre = 0;
        for (int i = 1; i < n; ++i) {
            int cur = nums[i] - nums[i - 1];
            if ((cur > 0 && pre <= 0) || (cur < 0 && pre >= 0)) {
                ++k;
                pre = cur;
            }
        }
        return k;
    }

    // int wiggleMaxLength(vector<int>& nums) {
    //     int n = nums.size();
    //     if (n < 2) return n;
    //     int up = 1;
    //     int down = 1;
    //     for (int i = 1; i < n; ++i) {
    //         if (nums[i] > nums[i - 1]) {
    //             up = down + 1;
    //         } else if (nums[i] < nums[i - 1]) {
    //             down = up + 1;
    //         }
    //     }
    //     return max(up, down);
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
        {{1, 7, 4, 9, 2, 5}, 6},
        {{1, 17, 5, 10, 13, 15, 10, 5, 16, 8}, 7},
        {{1, 2, 3, 4, 5, 6, 7, 8, 9}, 2},
    };

    for (auto& [nums, excepted] : CASES) {
        assert(o.wiggleMaxLength(nums) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [nums, _] : CASES) {
        for (auto i = 0; i < 100000; ++i) {
            o.wiggleMaxLength(nums);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
