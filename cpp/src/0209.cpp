/*
[209. Minimum Size Subarray Sum (Medium)](https://leetcode.com/problems/minimum-size-subarray-sum/)

@topic: Array
@topic: Binary Search
@topic: Sliding Window
@topic: Prefix Sum

Constraints:
  - `1 <= target <= 10^9`
  - `1 <= nums.length <= 10^5`
  - `1 <= nums[i] <= 10^4`
*/

#include <vector>

using std::min;
using std::vector;

class Solution {
   public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT_MAX;
        int sum = 0;
        int slow = 0;
        int fast = 0;
        int size = nums.size();
        while (fast < size) {
            sum += nums[fast++];
            while (sum >= target) {
                sum -= nums[slow++];
                res = min(res, fast - slow + 1);
            }
        }
        return res == INT_MAX ? 0 : res;
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

    vector<tuple<int, vector<int>, int>> CASES = {
        {7, {2, 3, 1, 2, 4, 3}, 2},
        {4, {1, 4, 4}, 1},
        {11, {1, 1, 1, 1, 1, 1, 1, 1}, 0},
    };

    for (auto& [target, nums, excepted] : CASES) {
        assert(o.minSubArrayLen(target, nums) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [target, nums, _] : CASES) {
        for (int i = 0; i < 100000; ++i) {
            o.minSubArrayLen(target, nums);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
