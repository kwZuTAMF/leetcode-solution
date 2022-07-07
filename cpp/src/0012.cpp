/*
[12. Integer to Roman (Medium)](https://leetcode.com/problems/integer-to-roman/)

@topic: Hash Table
@topic: Math
@topic: String

Constraints:
  - `1 <= num <= 3999`
*/

#include <string>

using std::string;

class Solution {
   public:
    string intToRoman(int num) {
        const static string thousands[] = {"", "M", "MM", "MMM"};
        const static string hundreds[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        const static string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        const static string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        return thousands[num / 1000] + hundreds[num % 1000 / 100] + tens[num % 100 / 10] + ones[num % 10];
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

    vector<tuple<int, string>> CASES = {
        {3, "III"},
        {58, "LVIII"},
        {1994, "MCMXCIV"},
    };

    for (auto& [num, excepted] : CASES) {
        assert(o.intToRoman(num) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [num, _] : CASES) {
        for (int i = 0; i < 100000; ++i) {
            o.intToRoman(num);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
