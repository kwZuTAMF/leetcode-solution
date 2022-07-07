/*
[35. Search Insert Position (Easy)](https://leetcode.com/problems/search-insert-position/)

@topic: Array
@topic: Binary Search

Constraints:
  - `1 <= nums.length <= 10^4`
  - `-10^4 <= nums[i] <= 10^4`
  - `nums` contains **distinct** values sorted in **ascending** order.
  - `-10^4 <= target <= 10^4`
*/

#include <vector>

using std::vector;

class Solution {
   public:
    int searchInsert(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = lo + ((hi - lo) >> 1);
            if (nums[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return lo;
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
        {{1, 3, 5, 6}, 5, 2},
        {{1, 3, 5, 6}, 2, 1},
        {{1, 3, 5, 6}, 7, 4},
    };

    for (auto& [nums, target, excepted] : CASES) {
        assert(o.searchInsert(nums, target) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [nums, target, _] : CASES) {
        for (auto i = 0; i < 100000; ++i) {
            o.searchInsert(nums, target);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
