/*
[15. 3Sum (Medium)](https://leetcode.com/problems/3sum/)

@topic: Array
@topic: Two Pointers
@topic: Sorting

Constraints:
  - `0 <= nums.length <= 3000`
  - `-10^5 <= nums[i] <= 10^5`
*/

#include <algorithm>
#include <vector>

using std::sort;
using std::vector;

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return {};
        sort(nums.begin(), nums.end());
        if (nums[0] > 0 || nums[n - 1] < 0) return {};
        vector<vector<int>> res;
        for (int i = 0; i < n - 2 && nums[i] <= 0; ++i) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                int p = i + 1;
                int q = n - 1;
                while (p < q) {
                    int s = nums[i] + nums[p] + nums[q];
                    if (s < 0) {
                        do {
                            ++p;
                        } while (p < q && nums[p] == nums[p - 1]);
                    } else if (s > 0) {
                        do {
                            --q;
                        } while (p < q && nums[q] == nums[q + 1]);
                    } else {
                        res.push_back({nums[i], nums[p], nums[q]});
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

    vector<tuple<vector<int>, vector<vector<int>>>> CASES = {
        {{-1, 0, 1, 2, -1, -4}, {{-1, -1, 2}, {-1, 0, 1}}},
        {{}, {}},
        {{0}, {}},
    };

    for (auto& [nums, excepted] : CASES) {
        assert(o.threeSum(nums) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [nums, _] : CASES) {
        for (int i = 0; i < 100000; ++i) {
            o.threeSum(nums);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
