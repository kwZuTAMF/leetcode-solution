/*
[454. 4Sum II (Medium)](https://leetcode.com/problems/4sum-ii/)

@topic: Array
@topic: Hash Table

Constraints:
  - `n == nums1.length`
  - `n == nums2.length`
  - `n == nums3.length`
  - `n == nums4.length`
  - `1 <= n <= 200`
  - `-2^28^ <= nums1[i], nums2[i], nums3[i], nums4[i] <= 2^28^`
*/

#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

class Solution {
   public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = 0;
        unordered_map<int, int> m;
        for (int x : nums1) for (int y : nums2) ++m[x + y];
        for (int x : nums3) for (int y : nums4) n += m.count(-x - y);
        return n;
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

    vector<tuple<vector<int>, vector<int>, vector<int>, vector<int>, int>> CASES = {
        {{1, 2}, {-2, -1}, {-1, 2}, {0, 2}, 2},
        {{0}, {0}, {0}, {0}, 1},
    };

    for (auto& [nums1, nums2, nums3, nums4, excepted] : CASES) {
        assert(o.fourSumCount(nums1, nums2, nums3, nums4) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [nums1, nums2, nums3, nums4, _] : CASES) {
        for (int i = 0; i < 100000; ++i) {
            o.fourSumCount(nums1, nums2, nums3, nums4);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
