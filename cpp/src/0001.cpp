/*
[1. Two Sum (Easy)](https://leetcode.com/problems/two-sum/)

@topic: Array
@topic: Hash Table

Constraints:
  - `2 <= nums.length <= 10^4`
  - `-10^9 <= nums[i] <= 10^9`
  - `-10^9 <= target <= 10^9`
  - **Only one valid answer exists.**
*/

#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0, n = nums.size(); i < n; ++i) {
            auto it = m.find(target - nums[i]);
            if (it != m.end()) {
                return {it->second, i};
            } else {
                m.emplace(nums[i], i);
            }
        }
        return {};
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

    vector<tuple<vector<int>, int, vector<int>>> CASES = {
        {{2, 7, 11, 15}, 9, {0, 1}},
        {{3, 2, 4}, 6, {1, 2}},
        {{3, 3}, 6, {0, 1}},
    };

    for (auto& [nums, target, excepted] : CASES) {
        assert(o.twoSum(nums, target) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [nums, target, _] : CASES) {
        for (auto i = 0; i < 100000; ++i) {
            o.twoSum(nums, target);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
