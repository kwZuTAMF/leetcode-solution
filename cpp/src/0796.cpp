/*
[796. Rotate String (Easy)](https://leetcode.com/problems/rotate-string/)

@topic: String
@topic: String Matching

Constraints:
  - `1 <= s.length, goal.length <= 100`
  - `s` and `goal` consist of lowercase English letters.
*/

#include <string>

using std::string;

class Solution {
   public:
    bool rotateString(string s, string goal) {
        return s.size() == goal.size() && (s + s).find(goal) != string::npos;
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
        {"abcde", "cdeab", true},
        {"abcde", "abced", false},
    };

    for (auto& [s, goal, excepted] : CASES) {
        assert(o.rotateString(s, goal) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [s, goal, _] : CASES) {
        for (auto i = 0; i < 100000; ++i) {
            o.rotateString(s, goal);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
