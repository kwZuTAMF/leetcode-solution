/*
[135. Candy (Hard)](https://leetcode.com/problems/candy/)

@topic: Array
@topic: Greedy

Constraints:
  - `n == ratings.length`
  - `1 <= n <= 2 * 10^4`
  - `0 <= ratings[i] <= 2 * 10^4`
*/

#include <numeric>
#include <vector>

using std::accumulate;
using std::max;
using std::vector;

class Solution {
   public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }
        for (int i = n - 1; i > 0; --i) {
            if (ratings[i] < ratings[i - 1]) {
                candies[i - 1] = max(candies[i - 1], candies[i] + 1);
            }
        }
        return accumulate(candies.begin(), candies.end(), 0);
    }

    // int candy(vector<int>& ratings) {
    //     int res = 1;
    //     int pre = 1;
    //     int inc = 1;
    //     int dec = 0;
    //     for (int i = 1, n = ratings.size(); i < n; ++i) {
    //         if (ratings[i] >= ratings[i - 1]) {
    //             res += inc = pre = ratings[i] == ratings[i - 1] ? 1 : pre + 1;
    //             dec = 0;
    //         } else {
    //             res += dec += dec == inc - 1 ? 2 : 1;
    //             pre = 1;
    //         }
    //     }
    //     return res;
    // }
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
        {{1, 0, 2}, 5},
        {{1, 2, 2}, 4},
    };

    for (auto& [ratings, excepted] : CASES) {
        assert(o.candy(ratings) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [ratings, _] : CASES) {
        for (auto i = 0; i < 100000; ++i) {
            o.candy(ratings);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
