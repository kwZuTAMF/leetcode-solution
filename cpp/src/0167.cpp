/*
[167. Two Sum II - Input Array Is Sorted (Medium)](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)

@topic: Array
@topic: Two Pointers
@topic: Binary Search

Constraints:
  - `2 <= numbers.length <= 3 * 10^4`
  - `-1000 <= numbers[i] <= 1000`
  - `numbers` is sorted in **non-decreasing order**.
  - `-1000 <= target <= 1000`
  - The tests are generated such that there is **exactly one solution**.
*/

#include <vector>

using std::vector;

class Solution {
   public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        while (i < j) {
            if (numbers[i] < target - numbers[j]) {
                ++i;
            } else if (numbers[i] > target - numbers[j]) {
                --j;
            } else {
                return {i + 1, j + 1};
            }
        }
        return {};
    }

    // vector<int> twoSum(vector<int>& numbers, int target) {
    //     for (int i = 0, n = numbers.size(); i < n; ++i) {
    //         int p = i + 1;
    //         int q = n - 1;
    //         while (p <= q) {
    //             int m = p + ((q - p) >> 1);
    //             if (numbers[m] < target - numbers[i]) {
    //                 p = m + 1;
    //             } else if (numbers[m] > target - numbers[i]) {
    //                 q = m - 1;
    //             } else {
    //                 return {i + 1, m + 1};
    //             }
    //         }
    //     }
    //     return {};
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
        {{2, 7, 11, 15}, 9, {1, 2}},
        {{2, 3, 4}, 6, {1, 3}},
        {{-1, 0}, -1, {1, 2}},
    };

    for (auto& [numbers, target, excepted] : CASES) {
        assert(o.twoSum(numbers, target) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [numbers, target, _] : CASES) {
        for (auto i = 0; i < 100000; ++i) {
            o.twoSum(numbers, target);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
