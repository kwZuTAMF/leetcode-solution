/*
[239. Sliding Window Maximum (Hard)](https://leetcode.com/problems/sliding-window-maximum/)

@topic: Array
@topic: Queue
@topic: Sliding Window
@topic: Heap (Priority Queue)
@topic: Monotonic Queue

Constraints:
  - `1 <= nums.length <= 10^5`
  - `-10^4 <= nums[i] <= 10^4`
  - `1 <= k <= nums.length`
*/

#include <vector>

using std::max;
using std::vector;

class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int m = nums[0];
        vector<int> res(n - k + 1);
        for (int i = 1; i < k; ++i) m = max(m, nums[i]);
        res[0] = m;
        for (int i = k; i < n; ++i) res[i - k + 1] = m = max(m, nums[i]);
        return res;
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
        {{1, 3, -1, -3, 5, 3, 6, 7}, 3, {3, 3, 5, 5, 6, 7}},
        {{1}, 1, {1}},
    };

    for (auto& [nums, k, excepted] : CASES) {
        assert(o.maxSlidingWindow(nums, k) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [nums, k, _] : CASES) {
        for (int i = 0; i < 100000; ++i) {
            o.maxSlidingWindow(nums, k);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
