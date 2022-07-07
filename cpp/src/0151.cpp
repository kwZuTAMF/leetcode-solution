/*
[151. Reverse Words in a String (Medium)](https://leetcode.com/problems/reverse-words-in-a-string/)

@topic: Two Pointers
@topic: String

Constraints:
  - `1 <= s.length <= 10^4`
  - `s` contains English letters (upper-case and lower-case), digits, and spaces `' '`.
  - There is **at least one** word in `s`.
*/

#include <string>
#include <vector>

using std::min;
using std::string;
using std::swap;
using std::vector;

class Solution {
   public:
    string reverseWords(string s) {
        int slow = 0, fast = 0, size = s.size();
        reverse(s, 0, size - 1);
        for (; fast < size; ++fast) {
            if (s[fast] != ' ') {
                if (slow > 0) s[slow++] = ' ';
                int k = fast;
                while (k < size && s[k] != ' ') s[slow++] = s[k++];
                reverse(s, slow - (k - fast), slow - 1);
                fast = k;
            }
        }
        s.resize(slow);
        return s;
    }

   private:
    void reverse(string& s, int i, int j) {
        while (i < j) swap(s[i++], s[j--]);
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

    vector<tuple<string, string>> CASES = {
        {"the sky is blue", "blue is sky the"},
        {"  hello world  ", "world hello"},
        {"a good   example", "example good a"},
    };

    for (auto& [s, excepted] : CASES) {
        assert(o.reverseWords(s) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [s, _] : CASES) {
        for (auto i = 0; i < 100000; ++i) {
            o.reverseWords(s);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
