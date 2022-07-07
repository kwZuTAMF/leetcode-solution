/*
[752. Open the Lock (Medium)](https://leetcode.com/problems/open-the-lock/)

@topic: Array
@topic: Hash Table
@topic: String
@topic: Breadth-First Search

Constraints:
  - `1 <= deadends.length <= 500`
  - `deadends[i].length == 4`
  - `target.length == 4`
  - target **will not be** in the list `deadends`.
  - `target` and `deadends[i]` consist of digits only.
*/

#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using std::queue;
using std::string;
using std::unordered_set;
using std::vector;

class Solution {
   public:
    int openLock(vector<string>& deadends, string target) {
        if (target == "0000") return 0;
        unordered_set<string> seen(deadends.begin(), deadends.end());
        if (seen.count("0000") || seen.count(target)) return -1;
        seen.insert("0000");
        queue<string> q;
        q.emplace("0000");
        int step = 0;
        int size;
        while ((size = q.size())) {
            for (int i = 0; i < size; ++i) {
                string curr = q.front(); q.pop();
                if (curr == target) return step;
                for (int k = 0; k < 4; ++k) {
                    string next = curr;
                    char c = next[k];
                    next[k] = c == '0' ? '9' : c - 1;
                    if (!seen.count(next)) {
                        seen.emplace(next);
                        q.push(next);
                    }
                    next[k] = c == '9' ? '0' : c + 1;
                    if (!seen.count(next)) {
                        seen.emplace(next);
                        q.push(next);
                    }
                }
            }
            ++step;
        }
        return -1;
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

    vector<tuple<vector<string>, string, int>> CASES = {
        {{"0201", "0101", "0102", "1212", "2002"}, "0202", 6},
        {{"8888"}, "0009", 1},
        {{"8887", "8889", "8878", "8898", "8788", "8988", "7888", "9888"}, "8888", -1},
    };

    for (auto& [deadends, target, excepted] : CASES) {
        assert(o.openLock(deadends, target) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [deadends, target, _] : CASES) {
        for (auto i = 0; i < 100; ++i) {
            o.openLock(deadends, target);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
