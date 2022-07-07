/*
[55. Jump Game (Medium)](https://leetcode.com/problems/jump-game/)

@topic: Array
@topic: Dynamic Programming
@topic: Greedy

Constraints:
  - `1 <= nums.length <= 10^4`
  - `0 <= nums[i] <= 10^5`
*/

#include <vector>

using std::max;
using std::vector;

class Solution {
   public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return true;
        int k = nums[0];
        if (k == 0) return false;
        for (int i = 1; i <= k; ++i) {
            k = max(k, i + nums[i]);
            if (k >= n - 1) return true;
        }
        return false;
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

    vector<tuple<vector<int>, bool>> CASES = {
        {{2, 3, 1, 1, 4}, true},
        {{3, 2, 1, 0, 4}, false},
    };

    for (auto& [nums, excepted] : CASES) {
        assert(o.canJump(nums) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [nums, _] : CASES) {
        for (auto i = 0; i < 100000; ++i) {
            o.canJump(nums);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
