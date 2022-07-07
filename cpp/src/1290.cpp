/*
[1290. Convert Binary Number in a Linked List to Integer (Easy)](https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/)

@topic: Linked List
@topic: Math

Constraints:
  - The Linked List is not empty.
  - Number of nodes will not exceed `30`.
  - Each node's value is either `0` or `1`.
*/

#include "structs/LinkedList.hpp"

class Solution {
   public:
    int getDecimalValue(ListNode* head) {
        auto n = 0;
        auto p = head;
        while (p) {
            n = n << 1 | p->val;
            p = p->next;
        }
        return n;
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
    using namespace LinkedList;

    Solution o;

    vector<tuple<ListNode*, int>> CASES = {
        {of({1, 0, 1}), 5},
        {of({0}), 0},
    };

    for (auto& [head, excepted] : CASES) {
        assert(o.getDecimalValue(head) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [head, _] : CASES) {
        for (auto i = 0; i < 100000; ++i) {
            o.getDecimalValue(head);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
