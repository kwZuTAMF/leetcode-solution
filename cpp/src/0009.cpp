/*
[9. Palindrome Number (Easy)](https://leetcode.com/problems/palindrome-number/)

@topic: Math

Constraints:
  - `-2^31 <= x <= 2^31 - 1`
*/

class Solution {
   public:
    bool isPalindrome(int x) {
        if (x <= 9) return x >= 0;
        if (x % 10 == 0) return false;
        int p = 0;
        int q = x;
        while (q > p) {
            p = p * 10 + q % 10;
            q /= 10;
        }
        return p == q || p / 10 == q;
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
        {121, true},
        {-121, false},
        {10, false},
    };

    for (auto& [x, excepted] : CASES) {
        assert(o.isPalindrome(x) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [x, _] : CASES) {
        for (int i = 0; i < 100000; ++i) {
            o.isPalindrome(x);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
