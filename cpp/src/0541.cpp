/*
[541. Reverse String II (Easy)](https://leetcode.com/problems/reverse-string-ii/)

@topic: Two Pointers
@topic: String

Constraints:
  - `1 <= s.length <= 10^4`
  - `s` consists of only lowercase English letters.
  - `1 <= k <= 10^4`
*/

#include <string>
#include <vector>

using std::min;
using std::string;
using std::swap;
using std::vector;

class Solution {
   public:
    string reverseStr(string s, int k) {
        for (int i = 0, n = s.size(); i < n; i += k << 1) {
            for (int p = i, q = min(n - 1, i + k - 1); p < q; ++p, --q) {
                swap(s[p], s[q]);
            }
        }
        return s;
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

    vector<tuple<string, int, string>> CASES = {
        {"abcdefg", 2, "bacdfeg"},
        {"abcd", 2, "bacd"},
    };

    for (auto& [s, k, excepted] : CASES) {
        assert(o.reverseStr(s, k) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [s, k, _] : CASES) {
        for (auto i = 0; i < 100000; ++i) {
            o.reverseStr(s, k);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
