/*
[34. Find First and Last Position of Element in Sorted Array (Medium)](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)

@topic: Array
@topic: Binary Search

Constraints:
  - `0 <= nums.length <= 10^5`
  - `-10^9 <= nums[i] <= 10^9`
  - `nums` is a non-decreasing array.
  - `-10^9 <= target <= 10^9`
*/

#include <vector>

using std::vector;

class Solution {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {
            search(nums, target, false),
            search(nums, target, true),
        };
    }

   private:
    int search(vector<int>& nums, int target, bool forward) {
        int lo = 0;
        int hi = nums.size() - 1;
        int i = -1;
        while (lo <= hi) {
            int mid = lo + ((hi - lo) >> 1);
            if (nums[mid] < target) {
                lo = mid + 1;
            } else if (nums[mid] > target) {
                hi = mid - 1;
            } else {
                i = mid;
                if (forward) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
        }
        return i;
    }

   public:
    // vector<int> searchRange(vector<int>& nums, int target) {
    //     int lo = 0, hi = nums.size() - 1, first = -1, last = -1;
    //     while (lo <= hi) {
    //         int mid = lo + ((hi - lo) >> 1);
    //         if (nums[mid] < target) {
    //             lo = mid + 1;
    //         } else if (nums[mid] > target) {
    //             hi = mid - 1;
    //         } else {
    //             hi = mid - 1;
    //             first = mid;
    //         }
    //     }
    //     if (first == -1) {
    //         return {-1, -1};
    //     }
    //     lo = first, hi = nums.size() - 1;
    //     while (lo <= hi) {
    //         int mid = lo + ((hi - lo) >> 1);
    //         if (nums[mid] < target) {
    //             lo = mid + 1;
    //         } else if (nums[mid] > target) {
    //             hi = mid - 1;
    //         } else {
    //             lo = mid + 1;
    //             last = mid;
    //         }
    //     }
    //     return {first, last};
    // }

    // vector<int> searchRange(vector<int>& nums, int target) {
    //     if (nums.empty()) {
    //         return {-1, -1};
    //     }
    //     int lo = 0, hi = nums.size() - 1;
    //     while (lo < hi) {
    //         int mid = lo + ((hi - lo) >> 1);
    //         if (nums[mid] < target) {
    //             lo = mid + 1;
    //         } else {
    //             hi = mid;
    //         }
    //     }
    //     if (nums[lo] != target) {
    //         return {-1, -1};
    //     }
    //     int first = lo;
    //     lo = hi, hi = nums.size() - 1;
    //     while (lo < hi) {
    //         int mid = lo + ((hi - lo + 1) >> 1);
    //         if (nums[mid] > target) {
    //             hi = mid - 1;
    //         } else {
    //             lo = mid;
    //         }
    //     }
    //     return {first, hi};
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

    vector<tuple<vector<int>, int, vector<int>>> CASES = {
        {{5, 7, 7, 8, 8, 10}, 8, {3, 4}},
        {{5, 7, 7, 8, 8, 10}, 6, {-1, -1}},
        {{}, 0, {-1, -1}},
    };

    for (auto& [nums, target, excepted] : CASES) {
        assert(o.searchRange(nums, target) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [nums, target, _] : CASES) {
        for (auto i = 0; i < 100000; ++i) {
            o.searchRange(nums, target);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
