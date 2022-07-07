/*
[374. Guess Number Higher or Lower (Easy)](https://leetcode.com/problems/guess-number-higher-or-lower/)

@topic: Binary Search
@topic: Interactive

Constraints:
  - `1 <= n <= 2^31 - 1`
  - `1 <= pick <= n`
*/

#include <vector>

using std::vector;

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

int pick;

int guess(int num) {
    if (pick < num) {
        return -1;
    } else if (pick > num) {
        return 1;
    } else {
        return 0;
    }
}

class Solution {
   public:
    int guessNumber(int n) {
        int lo = 1;
        int hi = n;
        while (lo < hi) {
            int mid = lo + ((hi - lo) >> 1);
            if (guess(mid) <= 0) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
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

    vector<tuple<int, int, int>> CASES = {
        {10, 6, 6},
        {1, 1, 1},
        {2, 1, 1},
    };

    for (auto& [n, pick, excepted] : CASES) {
        ::pick = pick;
        assert(o.guessNumber(n) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [n, pick, _] : CASES) {
        for (auto i = 0; i < 100000; ++i) {
            ::pick = pick;
            o.guessNumber(n);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
