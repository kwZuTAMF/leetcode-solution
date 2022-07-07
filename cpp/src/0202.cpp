/*
[202. Happy Number (Easy)](https://leetcode.com/problems/happy-number/)

@topic: Hash Table
@topic: Math
@topic: Two Pointers

Constraints:
  - `1 <= n <= 2^31 - 1`
*/

class Solution {
   public:
    bool isHappy(int n) {
        while (true) {
            switch (n) {
                case 1:
                    return true;
                case 4:
                case 16:
                case 20:
                case 37:
                case 42:
                case 58:
                case 89:
                case 145:
                    return false;
                default:
                    n = next(n);
                    break;
            }
        }
    }

    // bool isHappy(int n) {
    //     int slow = n;
    //     int fast = n;
    //     while (true) {
    //         slow = next(slow);
    //         fast = next(fast);
    //         fast = next(fast);
    //         if (fast == 1) {
    //             return true;
    //         }
    //         if (slow == fast) {
    //             return slow == 1;
    //         }
    //     }
    // }

   private:
    int next(int n) {
        int s = 0;
        while (n) {
            int m = n % 10;
            n /= 10;
            s += m * m;
        }
        return s;
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

    vector<tuple<int, bool>> CASES = {
        {19, true},
        {2, false},
    };

    for (auto& [n, excepted] : CASES) {
        assert(o.isHappy(n) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [n, _] : CASES) {
        for (int i = 0; i < 1000000; ++i) {
            o.isHappy(n);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
