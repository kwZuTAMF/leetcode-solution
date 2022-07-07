/*
[445. Add Two Numbers II (Medium)](https://leetcode.com/problems/add-two-numbers-ii/)

@topic: Linked List
@topic: Math
@topic: Stack

Constraints:
  - The number of nodes in each linked list is in the range `[1, 100]`.
  - `0 <= Node.val <= 9`
  - It is guaranteed that the list represents a number that does not have leading zeros.
*/

#include <stack>

#include "structs/LinkedList.hpp"

using std::stack;

class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        for (auto p = l1; p; p = p->next) s1.push(p->val);
        for (auto q = l2; q; q = q->next) s2.push(q->val);
        int carry = 0;
        ListNode* prev = nullptr;
        while (s1.size() || s2.size() || carry) {
            if (s1.size()) {
                carry += s1.top(); s1.pop();
            }
            if (s2.size()) {
                carry += s2.top(); s2.pop();
            }
            auto curr = new ListNode(carry % 10, prev);
            carry /= 10;
            prev = curr;
        }
        return prev;
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

    vector<tuple<ListNode*, ListNode*, ListNode*>> CASES = {
        {of({7, 2, 4, 3}), of({5, 6, 4}), of({7, 8, 0, 7})},
        {of({2, 4, 3}), of({5, 6, 4}), of({8, 0, 7})},
        {of({0}), of({0}), of({0})},
    };

    for (auto& [l1, l2, excepted] : CASES) {
        assert(eq(o.addTwoNumbers(l1, l2), excepted));
    }

    auto start = system_clock::now();
    for (auto& [l1, l2, _] : CASES) {
        for (auto i = 0; i < 100000; ++i) {
            o.addTwoNumbers(l1, l2);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
