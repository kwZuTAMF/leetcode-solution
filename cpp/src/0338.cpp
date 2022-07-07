/*
[338. Counting Bits (Easy)](https://leetcode.com/problems/counting-bits/)

@topic: Dynamic Programming
@topic: Bit Manipulation

Constraints:
  - `0 <= n <= 10^5`
*/

#include <vector>

using std::vector;

class Solution {
   public:
    vector<int> countBits(int n) {
        vector<int> counts(n + 1);
        for (int i = 1; i <= n; ++i)
            counts[i] = counts[i >> 1] + (i & 1);
        return counts;
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

    vector<tuple<int, vector<int>>> CASES = {
        {0, {0}},
        {1, {0, 1}},
        {2, {0, 1, 1}},
        {3, {0, 1, 1, 2}},
        {4, {0, 1, 1, 2, 1}},
        {5, {0, 1, 1, 2, 1, 2}},
        {6, {0, 1, 1, 2, 1, 2, 2}},
        {7, {0, 1, 1, 2, 1, 2, 2, 3}},
        {8, {0, 1, 1, 2, 1, 2, 2, 3, 1}},
        {9, {0, 1, 1, 2, 1, 2, 2, 3, 1, 2}},
        {10, {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2}},
        {11, {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3}},
        {12, {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2}},
        {13, {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3}},
        {14, {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3}},
        {15, {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4}},
    };

    for (auto& [n, excepted] : CASES) {
        assert(o.countBits(n) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [n, _] : CASES) {
        for (int i = 0; i < 100000; ++i) {
            o.countBits(n);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
