/*
[412. Fizz Buzz (Easy)](https://leetcode.com/problems/fizz-buzz/)

@topic: Math
@topic: String
@topic: Simulation

Constraints:
  - `1 <= n <= 10^4`
*/

#include <string>
#include <vector>

using std::string;
using std::to_string;
using std::vector;

class Solution {
   public:
    vector<string> fizzBuzz(int n) {
        vector<string> res(n);
        for (int i = 1; i <= n; ++i) {
            if (i % 3 == 0) {
                res[i - 1] = i % 5 == 0 ? "FizzBuzz" : "Fizz";
            } else {
                res[i - 1] = i % 5 == 0 ? "Buzz" : to_string(i);
            }
        }
        return res;
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

    vector<tuple<int, vector<string>>> CASES = {
        {3, {"1", "2", "Fizz"}},
        {5, {"1", "2", "Fizz", "4", "Buzz"}},
        {15, {"1", "2", "Fizz", "4", "Buzz", "Fizz", "7", "8", "Fizz", "Buzz", "11", "Fizz", "13", "14", "FizzBuzz"}},
    };

    for (auto& [n, excepted] : CASES) {
        assert(o.fizzBuzz(n) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [n, _] : CASES) {
        for (int i = 0; i < 100000; ++i) {
            o.fizzBuzz(n);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
