/*
[313. Super Ugly Number (Medium)](https://leetcode.com/problems/super-ugly-number/)

@topic: Array
@topic: Math
@topic: Dynamic Programming

Constraints:
  - `1 <= n <= 10^5`
  - `1 <= primes.length <= 100`
  - `2 <= primes[i] <= 1000`
  - `primes[i]` is **guaranteed** to be a prime number.
  - All the values of `primes` are **unique** and sorted in **ascending order**.
*/

#include <queue>
#include <unordered_set>
#include <vector>

using std::greater;
using std::priority_queue;
using std::unordered_set;
using std::vector;

class Solution {
   public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        unordered_set<int> seen;
        priority_queue<int, vector<int>, greater<int>> q;
        q.push(1);
        int ugly = 1;
        for (int i = 0; i < n; ++i) {
            ugly = q.top(); q.pop();
            for (int prime : primes) {
                int next = ugly * prime;
                if (seen.find(next) == seen.end()) {
                    seen.insert(next);
                    q.push(next);
                }
            }
        }
        return ugly;
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

    vector<tuple<int, vector<int>, int>> CASES = {
        {12, {2, 7, 13, 19}, 32},
        {1, {2, 3, 5}, 1},
    };

    for (auto& [n, primes, excepted] : CASES) {
        assert(o.nthSuperUglyNumber(n, primes) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [n, primes, _] : CASES) {
        for (auto i = 0; i < 10000; ++i) {
            o.nthSuperUglyNumber(n, primes);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
