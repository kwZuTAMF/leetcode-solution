/*
[263. Ugly Number (Easy)](https://leetcode.com/problems/ugly-number/)

@topic: Math

Constraints:
  - `-2^31 <= n <= 2^31 - 1`
*/

class Solution {
   public:
    bool isUgly(int n) {
        if (n <= 0) return false;
        if (n <= 10) return n != 7;
        while (n % 5 == 0) n /= 5;
        while (n % 3 == 0) n /= 3;
        while (n % 2 == 0) n /= 2;
        return n == 1;
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
        {6, true},
        {1, true},
        {14, false},
    };

    for (auto& [n, excepted] : CASES) {
        assert(o.isUgly(n) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [n, _] : CASES) {
        for (auto i = 0; i < 100000; ++i) {
            o.isUgly(n);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
