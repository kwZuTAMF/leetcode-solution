/*
[459. Repeated Substring Pattern (Easy)](https://leetcode.com/problems/repeated-substring-pattern/)

@topic: String
@topic: String Matching

Constraints:
  - `1 <= s.length <= 10^4`
  - `s` consists of lowercase English letters.
*/

#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
   public:
    bool repeatedSubstringPattern(string s) {
        return (s + s).find(s, 1) != s.size();
    }

    // bool repeatedSubstringPattern(string s) {
    //     int n = s.size();
    //     vector<int> next(n);
    //     for (int i = 1, j = 0; i < n; ++i) {
    //         while (j > 0 && s[i] != s[j]) j = next[j - 1];
    //         if (s[i] == s[j]) ++j;
    //         next[i] = j;
    //     }
    //     return next[n - 1] != 0 && n % (n - next[n - 1]) == 0;
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

    vector<tuple<string, bool>> CASES = {
        {"abab", true},
        {"aba", false},
        {"abcabcabcabc", true},
    };

    for (auto& [s, excepted] : CASES) {
        assert(o.repeatedSubstringPattern(s) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [s, _] : CASES) {
        for (auto i = 0; i < 100000; ++i) {
            o.repeatedSubstringPattern(s);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
