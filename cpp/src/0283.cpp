/*
[283. Move Zeroes (Easy)](https://leetcode.com/problems/move-zeroes/)

@topic: Array
@topic: Two Pointers

Constraints:
  - `1 <= nums.length <= 10^4`
  - `-2^31^ <= nums[i] <= 2^31^ - 1`
*/

#include <vector>

using std::swap;
using std::vector;

class Solution {
   public:
    // void moveZeroes(vector<int>& nums) {
    //     for (int i = 0, j = 0, n = nums.size(); i < n; ++i) {
    //         if (nums[j]) {
    //             ++j;
    //         } else if (nums[i]) {
    //             swap(nums[i], nums[j++]);
    //         }
    //     }
    // }

    void moveZeroes(vector<int>& nums) {
        for (int i = 0, k = 0, n = nums.size(); i < n; ++i) {
            if (nums[i] == 0) {
                ++k;
            } else if (k > 0) {
                swap(nums[i], nums[i - k]);
            }
        }
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

    vector<tuple<vector<int>, vector<int>>> CASES = {
        {{1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}},
        {{1, 2, 3, 4, 0}, {1, 2, 3, 4, 0}},
        {{0, 1, 0, 3, 12}, {1, 3, 12, 0, 0}},
        {{0}, {0}},
    };

    for (auto& [nums, excepted] : CASES) {
        o.moveZeroes(nums);
        assert(nums == excepted);
    }

    auto start = system_clock::now();
    for (auto i = 0; i < 100000; ++i) {
        auto nums = vector<int>{0, 1, 0, 3, 12};
        o.moveZeroes(nums);
        nums = vector<int>{0};
        o.moveZeroes(nums);
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
