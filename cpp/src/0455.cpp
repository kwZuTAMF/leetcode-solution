/*
[455. Assign Cookies (Easy)](https://leetcode.com/problems/assign-cookies/)

@topic: Array
@topic: Greedy
@topic: Sorting

Constraints:
  - `1 <= g.length <= 3 * 10^4`
  - `0 <= s.length <= 3 * 10^4`
  - `1 <= g[i], s[j] <= 2^31 - 1`
*/

#include <algorithm>
#include <vector>

using std::sort;
using std::vector;

class Solution {
   public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if (s.empty()) return 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, m = g.size();
        int j = 0, n = s.size();
        while (i < m && j < n) {
            if (g[i] <= s[j]) ++i;
            ++j;
        }
        return i;
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

    vector<tuple<vector<int>, vector<int>, int>> CASES = {
        {{1, 2, 3}, {1, 1}, 1},
        {{1, 2}, {1, 2, 3}, 2},
    };

    for (auto& [g, s, excepted] : CASES) {
        assert(o.findContentChildren(g, s) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [g, s, _] : CASES) {
        for (auto i = 0; i < 100000; ++i) {
            o.findContentChildren(g, s);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
