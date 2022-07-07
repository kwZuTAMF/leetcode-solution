/*
[347. Top K Frequent Elements (Medium)](https://leetcode.com/problems/top-k-frequent-elements/)

@topic: Array
@topic: Hash Table
@topic: Divide and Conquer
@topic: Sorting
@topic: Heap (Priority Queue)
@topic: Bucket Sort
@topic: Counting
@topic: Quickselect

Constraints:
  - `1 <= nums.length <= 10^5`
  - `k` is in the range `[1, the number of unique elements in the array]`.
  - It is **guaranteed** that the answer is **unique**.
*/

#include <queue>
#include <unordered_map>
#include <vector>

using std::pair;
using std::priority_queue;
using std::unordered_map;
using std::vector;

class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counter;
        for (int i : nums) ++counter[i];
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
        for (auto& it : counter) {
            q.push(it);
            if (q.size() > static_cast<size_t>(k)) {
                q.pop();
            }
        }
        vector<int> res(k);
        while (k--) {
            res[k] = q.top().first;
            q.pop();
        }
        return res;
    }

   private:
    struct cmp {
        bool operator()(pair<int, int>& lhs, pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }
    };
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
        {{1, 1, 1, 2, 2, 3}, 2, {1, 2}},
        {{1}, 1, {1}},
    };

    for (auto& [nums, k, excepted] : CASES) {
        assert(o.topKFrequent(nums, k) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [nums, k, _] : CASES) {
        for (auto i = 0; i < 100000; ++i) {
            o.topKFrequent(nums, k);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
