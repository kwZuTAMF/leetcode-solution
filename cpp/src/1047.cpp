/*
[1047. Remove All Adjacent Duplicates In String (Easy)](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/)

@topic: String
@topic: Stack

Constraints:
  - `1 <= s.length <= 10^5`
  - `s` consists of lowercase English letters.
*/

#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
   public:
    string removeDuplicates(string s) {
        string stk;
        for (char c : s) {
            if (stk.empty() || stk.back() != c) {
                stk.push_back(c);
            } else {
                stk.pop_back();
            }
        }
        return stk;
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

    vector<tuple<string, string>> CASES = {
        {"abbaca", "ca"},
        {"azxxzy", "ay"},
    };

    for (auto& [s, excepted] : CASES) {
        assert(o.removeDuplicates(s) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [s, _] : CASES) {
        for (int i = 0; i < 100000; ++i) {
            o.removeDuplicates(s);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
