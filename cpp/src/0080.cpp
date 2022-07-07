/*
[80. Remove Duplicates from Sorted Array II (Medium)](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/)

@topic: Array
@topic: Two Pointers

Constraints:
  - `1 <= nums.length <= 3 * 10^4`
  - `-10^4 <= nums[i] <= 10^4`
  - `nums` is sorted in **non-decreasing** order.
*/

#include <vector>

using std::vector;

class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        int k = 2, slow = k, fast = k, size = nums.size();
        if (size <= k) {
            return size;
        }
        for (; fast < size; ++fast) {
            if (nums[slow - k] != nums[fast]) {
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

    vector<tuple<vector<int>, int, vector<int>>> CASES = {
        {{1, 1, 1, 2, 2, 3}, 5, {1, 1, 2, 2, 3}},
        {{0, 0, 1, 1, 1, 1, 2, 3, 3}, 7, {0, 0, 1, 1, 2, 3, 3}},
    };

    for (auto& [nums, k, excepted] : CASES) {
        assert(o.removeDuplicates(nums) == k);
        for (int i = 0; i < k; ++i) {
            assert(nums[i] == excepted[i]);
        }
    }

    auto start = system_clock::now();
    for (int i = 0; i < 100000; ++i) {
        vector<int> nums = {1, 1, 1, 2, 2, 3};
        o.removeDuplicates(nums);
        nums = {0, 0, 1, 1, 1, 1, 2, 3, 3};
        o.removeDuplicates(nums);
    }

    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
