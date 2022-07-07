/*
[704. Binary Search (Easy)](https://leetcode.com/problems/binary-search/)

@topic: Array
@topic: Binary Search

Constraints:
  - `1 <= nums.length <= 10^4`
  - `-10^4 < nums[i], target < 10^4`
  - All the integers in `nums` are **unique**.
  - `nums` is sorted in ascending order.
*/

#include <vector>

using std::vector;

class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = lo + ((hi - lo) >> 1);
            if (nums[mid] < target) {
                lo = mid + 1;
            } else if (nums[mid] > target) {
                hi = mid - 1;
            } else {
                return mid;
            }
        }
        return -1;
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

    vector<tuple<vector<int>, int, int>> CASES = {
        {{-1, 0, 3, 5, 9, 12}, 9, 4},
        {{-1, 0, 3, 5, 9, 12}, 2, -1},
    };

    for (auto& [nums, target, excepted] : CASES) {
        assert(o.search(nums, target) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [nums, target, _] : CASES) {
        for (auto i = 0; i < 100000; ++i) {
            o.search(nums, target);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
