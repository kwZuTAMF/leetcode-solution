/*
[1780. Check if Number is a Sum of Powers of Three (Medium)](https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/)

@topic: Math

Constraints:
  - `1 <= n <= 10^7`
*/

class Solution {
   public:
    bool checkPowersOfThree(int n) {
        for (; n; n /= 3)
            if (n % 3 == 2)
                return false;
        return true;
    }
};

#include <cassert>
#include <chrono>
#include <iostream>
#include <vector>

using std::tuple;
using std::vector;
using std::chrono::duration_cast;
using std::chrono::microseconds;
using std::chrono::system_clock;

int main() {
    Solution o;

    vector<tuple<int, bool>> CASES = {
        {12, true},
        {91, true},
        {21, false},
    };

    for (auto& [n, excepted] : CASES) {
        assert(o.checkPowersOfThree(n) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [n, _] : CASES) {
        for (int i = 0; i < 100000; ++i) {
            o.checkPowersOfThree(n);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
