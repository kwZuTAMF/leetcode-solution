/*
[20. Valid Parentheses (Easy)](https://leetcode.com/problems/valid-parentheses/)

@topic: String
@topic: Stack

Constraints:
  - `1 <= s.length <= 10^4`
  - `s` consists of parentheses only `'()[]{}'`.
*/

#include <string>

using std::string;

class Solution {
   public:
    bool isValid(string s) {
        if (s.size() & 1) {
            return false;
        }
        string stk;
        for (char c : s) {
            if (c == '(') {
                stk.push_back(')');
            } else if (c == '[') {
                stk.push_back(']');
            } else if (c == '{') {
                stk.push_back('}');
            } else if (stk.empty() || stk.back() != c) {
                return false;
            } else {
                stk.pop_back();
            }
        }
        return stk.empty();
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

    vector<tuple<string, bool>> CASES = {
        {"()", true},
        {"()[]{}", true},
        {"(]", false},
    };

    for (auto& [s, excepted] : CASES) {
        assert(o.isValid(s) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [s, _] : CASES) {
        for (int i = 0; i < 100000; ++i) {
            o.isValid(s);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
