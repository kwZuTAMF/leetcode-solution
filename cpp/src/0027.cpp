/*
[27. Remove Element (Easy)](https://leetcode.com/problems/remove-element/)

@topic: Array
@topic: Two Pointers

Constraints:
  - `0 <= nums.length <= 100`
  - `0 <= nums[i] <= 50`
  - `0 <= val <= 100`
*/

#include <vector>

using std::vector;

class Solution {
   public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0, fast = 0, size = nums.size();
        for (; fast < size; ++fast) {
            if (nums[fast] != val) {
                nums[slow++] = nums[fast];
            }
        }
        return slow;
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

    vector<tuple<vector<int>, int, int, vector<int>>> CASES = {
        {{3, 2, 2, 3}, 3, 2, {2, 2}},
        {{0, 1, 2, 2, 3, 0, 4, 2}, 2, 5, {0, 1, 3, 0, 4}},
    };

    for (auto& [nums, val, k, excepted] : CASES) {
        assert(o.removeElement(nums, val) == k);
        for (int i = 0; i < k; ++i) {
            assert(nums[i] == excepted[i]);
        }
    }

    auto start = system_clock::now();
    for (int i = 0; i < 100000; ++i) {
        vector<int> nums = {3, 2, 2, 3};
        o.removeElement(nums, 3);
        nums = {0, 1, 2, 2, 3, 0, 4, 2};
        o.removeElement(nums, 2);
    }

    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
