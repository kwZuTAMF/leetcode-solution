/*
[383. Ransom Note (Easy)](https://leetcode.com/problems/ransom-note/)

@topic: Hash Table
@topic: String
@topic: Counting

Constraints:
  - `1 <= ransomNote.length, magazine.length <= 10^5`
  - `ransomNote` and `magazine` consist of lowercase English letters.
*/

#include <string>

using std::string;

class Solution {
   public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size()) return false;
        int freq[26]{};
        for (char c : magazine) ++freq[c - 'a'];
        for (char c : ransomNote) if (--freq[c - 'a'] < 0) return false;
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
        {"a", "b", false},
        {"aa", "ab", false},
        {"aa", "aab", true},
    };

    for (auto& [ransomNote, magazine, excepted] : CASES) {
        assert(o.canConstruct(ransomNote, magazine) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [ransomNote, magazine, _] : CASES) {
        for (int i = 0; i < 100000; ++i) {
            o.canConstruct(ransomNote, magazine);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
