/*
[977. Squares of a Sorted Array (Easy)](https://leetcode.com/problems/squares-of-a-sorted-array/)

@topic: Array
@topic: Two Pointers
@topic: Sorting

Constraints:
  - `1 <= nums.length <= 10^4`
  - `-10^4 <= nums[i] <= 10^4`
  - `nums` is sorted in **non-decreasing** order.
*/

#include <vector>

using std::vector;

class Solution {
   public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> squares(n);
        for (int i = 0, j = n - 1, k = j; i <= j; --k) {
            if (-nums[i] > nums[j]) {
                squares[k] = nums[i] * nums[i];
                ++i;
            } else {
                squares[k] = nums[j] * nums[j];
                --j;
            }
        }
        return squares;
    }

    // vector<int> sortedSquares(vector<int>& nums) {
    //     int n = nums.size();
    //     int m = 0;
    //     int p = 0;
    //     int q = n - 1;
    //     while (p <= q) {
    //         m = p + ((q - p) >> 1);
    //         if (nums[m] < 0)
    //             p = m + 1;
    //         else
    //             q = m - 1;
    //     }
    //     int i = m, j = m + 1, k = 0;
    //     vector<int> squares(n);
    //     while (i >= 0 && j < n) {
    //         if (-nums[i] < nums[j]) {
    //             squares[k++] = nums[i] * nums[i];
    //             --i;
    //         } else {
    //             squares[k++] = nums[j] * nums[j];
    //             ++j;
    //         }
    //     }
    //     for (; i >= 0; --i) squares[k++] = nums[i] * nums[i];
    //     for (; j < n; ++j) squares[k++] = nums[j] * nums[j];
    //     return squares;
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

    vector<tuple<vector<int>, vector<int>>> CASES = {
        {{-4, -1, 0, 3, 10}, {0, 1, 9, 16, 100}},
        {{-7, -3, 2, 3, 11}, {4, 9, 9, 49, 121}},
    };

    for (auto& [nums, excepted] : CASES) {
        assert(o.sortedSquares(nums) == excepted);
    }

    auto start = system_clock::now();
    for (int i = 0; i < 100000; ++i) {
        vector<int> nums = {-4, -1, 0, 3, 10};
        o.sortedSquares(nums);
        nums = {-7, -3, 2, 3, 11};
        o.sortedSquares(nums);
    }

    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
