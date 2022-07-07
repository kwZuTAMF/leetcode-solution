/*
[204. Count Primes (Medium)](https://leetcode.com/problems/count-primes/)

@topic: Array
@topic: Math
@topic: Enumeration
@topic: Number Theory

Constraints:
  - `0 <= n <= 5 * 10^6`
*/

#include <vector>

using std::vector;

class Solution {
   public:
    int countPrimes(int n) {
        if (n < 3) return 0;
        int count = n >> 1;
        vector<bool> sieve(n);
        for (int i = 3; i * i < n; i += 2) {
            if (!sieve[i]) {
                for (int j = i * i; j < n; j += i << 1) {
                    if (!sieve[j]) {
                        sieve[j] = true;
                        --count;
                    }
                }
            }
        }
        return count;
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

    vector<tuple<int, int>> CASES = {
        {0, 0},
        {1, 0},
        {2, 0},
        {3, 1},
        {4, 2},
        {5, 2},
        {6, 3},
        {7, 3},
        {8, 4},
        {9, 4},
        {10, 4},
        {11, 4},
        {12, 5},
        {13, 5},
        {14, 6},
        {15, 6},
        {10000, 1229},
        {499979, 41537},
        {999983, 78497},
        {1500000, 114155},
    };

    for (auto& [n, excepted] : CASES) {
        assert(o.countPrimes(n) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [n, _] : CASES) {
        for (int i = 0; i < 100; ++i) {
            o.countPrimes(n);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
