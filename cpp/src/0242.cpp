/*
[242. Valid Anagram (Easy)](https://leetcode.com/problems/valid-anagram/)

@topic: Hash Table
@topic: String
@topic: Sorting

Constraints:
  - `1 <= s.length, t.length <= 5 * 10^4`
  - `s` and `t` consist of lowercase English letters.
*/

#include <string>

using std::string;

class Solution {
   public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        char freq[26]{};
        for (char c : s) ++freq[c - 'a'];
        for (char c : t) if (--freq[c - 'a'] < 0) return false;
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

    vector<tuple<string, string, bool>> CASES = {
        {"anagram", "nagaram", true},
        {"rat", "car", false},
    };

    for (auto& [s, t, excepted] : CASES) {
        assert(o.isAnagram(s, t) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [s, t, _] : CASES) {
        for (int i = 0; i < 100000; ++i) {
            o.isAnagram(s, t);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
