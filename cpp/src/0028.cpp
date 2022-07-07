/*
[28. Implement strStr() (Easy)](https://leetcode.com/problems/implement-strstr/)

@topic: Two Pointers
@topic: String
@topic: String Matching

Constraints:
  - `1 <= haystack.length, needle.length <= 10^4`
  - `haystack` and `needle` consist of only lowercase English characters.
*/

#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
   public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        if (m == 0) return 0;
        vector<int> next(m);
        for (int i = 1, j = 0; i < m; ++i) {
            while (j > 0 && needle[i] != needle[j]) j = next[j - 1];
            if (needle[i] == needle[j]) ++j;
            next[i] = j;
        }
        for (int i = 0, j = 0; i < n; ++i) {
            while (j > 0 && haystack[i] != needle[j]) j = next[j - 1];
            if (haystack[i] == needle[j]) ++j;
            if (j == m) return i - m + 1;
        }
        return -1;
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

    vector<tuple<string, string, int>> CASES = {
        {"hello", "ll", 2},
        {"aaaaa", "bba", -1},
    };

    for (auto& [haystack, needle, excepted] : CASES) {
        assert(o.strStr(haystack, needle) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [haystack, needle, _] : CASES) {
        for (auto i = 0; i < 100000; ++i) {
            o.strStr(haystack, needle);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
