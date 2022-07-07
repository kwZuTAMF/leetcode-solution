/*
[53. Maximum Subarray (Medium)](https://leetcode.com/problems/maximum-subarray/)

@topic: Array
@topic: Divide and Conquer
@topic: Dynamic Programming

Constraints:
  - `1 <= nums.length <= 10^5`
  - `-10^4 <= nums[i] <= 10^4`
*/

#include <vector>

using std::max;
using std::vector;

class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int pre = nums[0];
        for (int i = 1, n = nums.size(); i < n; ++i) {
            pre = max(pre + nums[i], 0);
            res = max(pre, res);
        }
        return res;
    }

    // int maxSubArray(vector<int>& nums) {
    //     int res = nums[0];
    //     int pre = nums[0];
    //     for (int i = 1, n = nums.size(); i < n; ++i) {
    //         pre = max(pre + nums[i], nums[i]);
    //         res = max(pre, res);
    //     }
    //     return res;
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
        {{-2, 1, -3, 4, -1, 2, 1, -5, 4}, 6},
        {{1}, 1},
        {{5, 4, -1, 7, 8}, 23},
    };

    for (auto& [nums, excepted] : CASES) {
        assert(o.maxSubArray(nums) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [nums, _] : CASES) {
        for (auto i = 0; i < 100000; ++i) {
            o.maxSubArray(nums);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
