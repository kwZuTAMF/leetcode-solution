/*
[150. Evaluate Reverse Polish Notation (Medium)](https://leetcode.com/problems/evaluate-reverse-polish-notation/)

@topic: Array
@topic: Math
@topic: Stack

Constraints:
  - `1 <= tokens.length <= 10^4`
  - `tokens[i]` is either an operator: `"+"`, `"-"`, `"*"`, or `"/"`, or an integer in the range `[-200, 200]`.
*/

#include <string>
#include <vector>

using std::stoi;
using std::string;
using std::vector;

class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        int top = -1;
        vector<int> stk((tokens.size() + 1) >> 1);
        for (const string& token : tokens) {
            if (token == "+") {
                --top;
                stk[top] += stk[top + 1];
            } else if (token == "-") {
                --top;
                stk[top] -= stk[top + 1];
            } else if (token == "*") {
                --top;
                stk[top] *= stk[top + 1];
            } else if (token == "/") {
                --top;
                stk[top] /= stk[top + 1];
            } else {
                stk[++top] = stoi(token);
            }
        }
        return stk[0];
    }

    // int evalRPN(vector<string>& tokens) {
    //     int top = -1;
    //     vector<int> stk((tokens.size() + 1) >> 1);
    //     for (const string& token : tokens) {
    //         if (token == "+") {
    //             stk[--top] += stk[top];
    //         } else if (token == "-") {
    //             stk[--top] -= stk[top];
    //         } else if (token == "*") {
    //             stk[--top] *= stk[top];
    //         } else if (token == "/") {
    //             stk[--top] /= stk[top];
    //         } else {
    //             stk[++top] = stoi(token);
    //         }
    //     }
    //     return stk[0];
    // }
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

    vector<tuple<vector<string>, int>> CASES = {
        {{"2", "1", "+", "3", "*"}, 9},
        {{"4", "13", "5", "/", "+"}, 6},
        {{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"}, 22},
    };

    for (auto& [tokens, excepted] : CASES) {
        assert(o.evalRPN(tokens) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [tokens, _] : CASES) {
        for (auto i = 0; i < 100000; ++i) {
            o.evalRPN(tokens);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
