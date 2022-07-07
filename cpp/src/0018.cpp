/*
[18. 4Sum (Medium)](https://leetcode.com/problems/4sum/)

@topic: Array
@topic: Two Pointers
@topic: Sorting

Constraints:
  - `1 <= nums.length <= 200`
  - `-10^9 <= nums[i] <= 10^9`
  - `-10^9 <= target <= 10^9`
*/

#include <algorithm>
#include <vector>

using std::sort;
using std::vector;

class Solution {
   public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 4) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            if (nums[i] + nums[n - 1] < target - nums[n - 2] - nums[n - 3]) continue;
            if (nums[i] + nums[i + 1] > target - nums[i + 2] - nums[i + 3]) break;
            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                if (nums[i] + nums[j] < target - nums[n - 1] - nums[n - 2]) continue;
                if (nums[i] + nums[j] > target - nums[j + 1] - nums[j + 2]) break;
                int p = j + 1;
                int q = n - 1;
                while (p < q) {
                    if (nums[i] + nums[j] < target - nums[p] - nums[q]) {
                        do {
                            ++p;
                        } while (p < q && nums[p] == nums[p - 1]);
                    } else if (nums[i] + nums[j] > target - nums[p] - nums[q]) {
                        do {
                            --q;
                        } while (p < q && nums[q] == nums[q + 1]);
                    } else {
                        res.push_back({nums[i], nums[j], nums[p], nums[q]});
                        do {
                            ++p;
                        } while (p < q && nums[p] == nums[p - 1]);
                        do {
                            --q;
                        } while (p < q && nums[q] == nums[q + 1]);
                    }
                }
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

    vector<tuple<vector<int>, int, vector<vector<int>>>> CASES = {
        {{1, 0, -1, 0, -2, 2}, 0, {{-2, -1, 1, 2}, {-2, 0, 0, 2}, {-1, 0, 0, 1}}},
        {{2, 2, 2, 2, 2}, 8, {{2, 2, 2, 2}}},
    };

    for (auto& [nums, target, excepted] : CASES) {
        assert(o.fourSum(nums, target) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [nums, target, _] : CASES) {
        for (int i = 0; i < 100000; ++i) {
            o.fourSum(nums, target);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
