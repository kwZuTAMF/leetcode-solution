/*
[268. Missing Number (Easy)](https://leetcode.com/problems/missing-number/)

@topic: Array
@topic: Hash Table
@topic: Math
@topic: Binary Search
@topic: Bit Manipulation
@topic: Sorting

Constraints:
  - `n == nums.length`
  - `1 <= n <= 10^4`
  - `0 <= nums[i] <= n`
  - All the numbers of `nums` are **unique**.
*/

#include <vector>

using std::vector;

class Solution {
   public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        for (int i : nums) s += i;
        return n * (n + 1) / 2 - s;
    }

    // int missingNumber(vector<int>& nums) {
    //     int n = nums.size();
    //     int x;
    //     switch (n % 4) {
    //         case 0: x = n; break;
    //         case 1: x = 1; break;
    //         case 2: x = n + 1; break;
    //         default: x = 0; break;
    //     }
    //     for (int i : nums) x ^= i;
    //     return x;
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

    vector<tuple<vector<int>, int>> CASES = {
        {{3, 0, 1}, 2},
        {{0, 1}, 2},
        {{9, 6, 4, 2, 3, 5, 7, 0, 1}, 8},
    };

    for (auto& [nums, excepted] : CASES) {
        assert(o.missingNumber(nums) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [nums, _] : CASES) {
        for (int i = 0; i < 100000; ++i) {
            o.missingNumber(nums);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
