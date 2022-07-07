/*
[189. Rotate Array (Medium)](https://leetcode.com/problems/rotate-array/)

@topic: Array
@topic: Math
@topic: Two Pointers

Constraints:
  - `1 <= nums.length <= 10^5`
  - `-2^31 <= nums[i] <= 2^31 - 1`
  - `0 <= k <= 10^5`
*/

#include <vector>

using std::swap;
using std::vector;

class Solution {
   public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (k %= n) {
            reverse(nums, 0, n - 1);
            reverse(nums, 0, k - 1);
            reverse(nums, k, n - 1);
        }
    }

   private:
    void reverse(vector<int>& nums, int i, int j) {
        while (i < j) swap(nums[i++], nums[j--]);
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
        {{1, 2, 3, 4, 5, 6, 7}, 3, {5, 6, 7, 1, 2, 3, 4}},
        {{-1, -100, 3, 99}, 2, {3, 99, -1, -100}},
    };

    for (auto& [nums, k, excepted] : CASES) {
        o.rotate(nums, k);
        assert(nums == excepted);
    }

    auto start = system_clock::now();
    for (int i = 0; i < 100000; ++i) {
        auto nums = vector<int>{1, 2, 3, 4, 5, 6, 7};
        o.rotate(nums, 3);
        nums = vector<int>{-1, -100, 3, 99};
        o.rotate(nums, 2);
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
