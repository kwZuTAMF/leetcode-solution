/*
[344. Reverse String (Easy)](https://leetcode.com/problems/reverse-string/)

@topic: Two Pointers
@topic: String
@topic: Recursion

Constraints:
  - `1 <= s.length <= 10^5`
  - `s[i]` is a [printable ascii character](https://en.wikipedia.org/wiki/ASCII#Printable_characters).
*/

#include <string>
#include <vector>

using std::string;
using std::swap;
using std::vector;

class Solution {
   public:
    void reverseString(vector<char>& s) {
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
            swap(s[i], s[j]);
        }
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

    vector<tuple<vector<char>, vector<char>>> CASES = {
        {{'h', 'e', 'l', 'l', 'o'}, {'o', 'l', 'l', 'e', 'h'}},
        {{'H', 'a', 'n', 'n', 'a', 'h'}, {'h', 'a', 'n', 'n', 'a', 'H'}},
    };

    for (auto& [s, excepted] : CASES) {
        o.reverseString(s);
        assert(s == excepted);
    }

    auto start = system_clock::now();
    for (auto i = 0; i < 100000; ++i) {
        auto s = vector<char>{'h', 'e', 'l', 'l', 'o'};
        o.reverseString(s);
        s = vector<char>{'H', 'a', 'n', 'n', 'a', 'h'};
        o.reverseString(s);
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
