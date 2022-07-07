/*
[1002. Find Common Characters (Easy)](https://leetcode.com/problems/find-common-characters/)

@topic: Array
@topic: Hash Table
@topic: String

Constraints:
  - `1 <= words.length <= 100`
  - `1 <= words[i].length <= 100`
  - `words[i]` consists of lowercase English letters.
*/

#include <algorithm>
#include <string>
#include <vector>

using std::min;
using std::string;
using std::vector;

class Solution {
   public:
    vector<string> commonChars(vector<string>& words) {
        int freq[26]{};
        for (char c : words[0]) ++freq[c - 'a'];
        for (int i = 1, n = words.size(); i < n; ++i) {
            int hash[26]{};
            for (char c : words[i]) ++hash[c - 'a'];
            for (int i = 0; i < 26; ++i) freq[i] = min(freq[i], hash[i]);
        }
        vector<string> chars;
        for (int i = 0; i < 26; ++i)
            while (freq[i]--) chars.emplace_back(1, i + 'a');
        return chars;
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

    vector<tuple<vector<string>, vector<string>>> CASES = {
        {{"bella", "label", "roller"}, {"e", "l", "l"}},
        {{"cool", "lock", "cook"}, {"c", "o"}},
    };

    for (auto& [words, excepted] : CASES) {
        assert(o.commonChars(words) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [words, _] : CASES) {
        for (int i = 0; i < 100000; ++i) {
            o.commonChars(words);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
