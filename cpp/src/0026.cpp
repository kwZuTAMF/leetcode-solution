/*
[26. Remove Duplicates from Sorted Array (Easy)](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)

@topic: Array
@topic: Two Pointers

Constraints:
  - `1 <= nums.length <= 3 * 10^4`
  - `-100 <= nums[i] <= 100`
  - `nums` is sorted in **non-decreasing** order.
*/

#include <vector>

using std::vector;

class Solution {
   public:
    // int removeDuplicates(vector<int>& nums) {
    //     int slow = 0, fast = 0, size = nums.size();
    //     for (; fast < size; ++fast) {
    //         if (nums[fast] != nums[slow]) {
    //             nums[++slow] = nums[fast];
    //         }
    //     }
    //     return slow + 1;
    // }

    int removeDuplicates(vector<int>& nums) {
        int k = 1, slow = k, fast = k, size = nums.size();
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
        {{1, 1, 2}, 2, {1, 2}},
        {{0, 0, 1, 1, 1, 2, 2, 3, 3, 4}, 5, {0, 1, 2, 3, 4}},
    };

    for (auto& [nums, k, excepted] : CASES) {
        assert(o.removeDuplicates(nums) == k);
        for (int i = 0; i < k; ++i) {
            assert(nums[i] == excepted[i]);
        }
    }

    auto start = system_clock::now();
    for (int i = 0; i < 100000; ++i) {
        vector<int> nums = {1, 1, 2};
        o.removeDuplicates(nums);
        nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
        o.removeDuplicates(nums);
    }

    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
