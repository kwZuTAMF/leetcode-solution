/*
[11. Container With Most Water (Medium)](https://leetcode.com/problems/container-with-most-water/)

@topic: Array
@topic: Two Pointers
@topic: Greedy

Constraints:
  - `n == height.length`
  - `2 <= n <= 10^5`
  - `0 <= height[i] <= 10^4`
*/

#include <vector>

using std::max;
using std::min;
using std::vector;

class Solution {
   public:
    int maxArea(vector<int>& height) {
        int res = 0;
        for (int i = 0, j = height.size() - 1; i < j;) {
            res = max(res, min(height[i], height[j]) * (j - i));
            if (height[i] <= height[j]) {
                ++i;
            } else {
                --j;
            }
        }
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

    vector<tuple<vector<int>, int>> CASES = {
        {{1, 8, 6, 2, 5, 4, 8, 3, 7}, 49},
        {{1, 1}, 1},
    };

    for (auto& [height, excepted] : CASES) {
        assert(o.maxArea(height) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [height, _] : CASES) {
        for (auto i = 0; i < 100000; ++i) {
            o.maxArea(height);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
