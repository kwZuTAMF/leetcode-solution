/*
[349. Intersection of Two Arrays (Easy)](https://leetcode.com/problems/intersection-of-two-arrays/)

@topic: Array
@topic: Hash Table
@topic: Two Pointers
@topic: Binary Search
@topic: Sorting

Constraints:
  - `1 <= nums1.length, nums2.length <= 1000`
  - `0 <= nums1[i], nums2[i] <= 1000`
*/

#include <unordered_set>
#include <vector>

using std::swap;
using std::unordered_set;
using std::vector;

class Solution {
   public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>* xs = &nums1;
        vector<int>* ys = &nums2;
        if (xs->size() > ys->size()) swap(xs, ys);
        bool hash[1001]{};
        for (int i : *xs) hash[i] = true;
        vector<int> res;
        res.reserve(1001);
        int k = xs->size();
        for (int i : *ys) {
            if (k == 0) break;
            if (hash[i]) {
                hash[i] = false;
                res.emplace_back(i);
                --k;
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

    vector<tuple<vector<int>, vector<int>, vector<int>>> CASES = {
        {{1, 2, 2, 1}, {2, 2}, {2}},
        {{4, 9, 5}, {9, 4, 9, 8, 4}, {9, 4}},
    };

    for (auto& [nums1, nums2, excepted] : CASES) {
        assert(o.intersection(nums1, nums2) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [nums1, nums2, _] : CASES) {
        for (int i = 0; i < 100000; ++i) {
            o.intersection(nums1, nums2);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
