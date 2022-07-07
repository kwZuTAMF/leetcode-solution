/*
[13. Roman to Integer (Easy)](https://leetcode.com/problems/roman-to-integer/)

@topic: Hash Table
@topic: Math
@topic: String

Constraints:
  - `1 <= s.length <= 15`
  - `s` contains only the characters `('I', 'V', 'X', 'L', 'C', 'D', 'M')`.
  - It is **guaranteed** that `s` is a valid roman numeral in the range `[1, 3999]`.
*/

#include <string>

using std::string;

class Solution {
   public:
    int romanToInt(string s) {
        int n = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            switch (s[i]) {
                case 'I': n += n < 5 ? 1 : -1; break;
                case 'V': n += 5; break;
                case 'X': n += n < 50 ? 10 : -10; break;
                case 'L': n += 50; break;
                case 'C': n += n < 500 ? 100 : -100; break;
                case 'D': n += 500; break;
                case 'M': n += 1000; break;
            }
        }
        return n;
    }

    // int romanToInt(string s) {
    //     auto n = 0;
    //     auto p = 0;
    //     for (auto c : s) {
    //         switch (c) {
    //             case 'M': n += p == 'C' ? 800 : 1000; break;
    //             case 'D': n += p == 'C' ? 300 : 500; break;
    //             case 'C': n += p == 'X' ? 80 : 100; break;
    //             case 'L': n += p == 'X' ? 30 : 50; break;
    //             case 'X': n += p == 'I' ? 8 : 10; break;
    //             case 'V': n += p == 'I' ? 3 : 5; break;
    //             case 'I': n += 1;
    //         }
    //         p = c;
    //     }
    //     return n;
    // }
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

    vector<tuple<string, int>> CASES = {
        {"III", 3},
        {"LVIII", 58},
        {"MCMXCIV", 1994},
    };

    for (auto& [s, excepted] : CASES) {
        assert(o.romanToInt(s) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [s, _] : CASES) {
        for (int i = 0; i < 100000; ++i) {
            o.romanToInt(s);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
