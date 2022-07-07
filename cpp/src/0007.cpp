/*
[7. Reverse Integer (Medium)](https://leetcode.com/problems/reverse-integer/)

@topic: Math

Constraints:
  - `-2^31 <= x <= 2^31 - 1`
*/

class Solution {
   public:
    int reverse(int x) {
        int rev = 0;
        while (x) {
            if (rev < -214748364 || rev > 214748364) return 0;
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return rev;
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

    vector<tuple<int, int>> CASES = {
        {123, 321},
        {-123, -321},
        {120, 21},
        {2147483648, 0},
        {-2147483648, 0},
    };

    for (auto& [x, excepted] : CASES) {
        assert(o.reverse(x) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [x, _] : CASES) {
        for (int i = 0; i < 100000; ++i) {
            o.reverse(x);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
