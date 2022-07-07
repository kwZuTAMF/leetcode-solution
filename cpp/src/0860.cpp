/*
[860. Lemonade Change (Easy)](https://leetcode.com/problems/lemonade-change/)

@topic: Array
@topic: Greedy

Constraints:
  - `1 <= bills.length <= 10^5`
  - `bills[i]` is either `5`, `10`, or `20`.
*/

#include <numeric>
#include <vector>

using std::accumulate;
using std::max;
using std::vector;

class Solution {
   public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for (int bill : bills) {
            if (bill == 5) {
                ++five;
            } else if (bill == 10) {
                if (five) {
                    --five;
                    ++ten;
                } else {
                    return false;
                }
            } else {
                if (five && ten) {
                    --five;
                    --ten;
                } else if (five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
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

    vector<tuple<vector<int>, bool>> CASES = {
        {{5, 5, 5, 10, 20}, true},
        {{5, 5, 10, 10, 20}, false},
    };

    for (auto& [bills, excepted] : CASES) {
        assert(o.lemonadeChange(bills) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [bills, _] : CASES) {
        for (auto i = 0; i < 100000; ++i) {
            o.lemonadeChange(bills);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
