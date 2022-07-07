/*
[2. Add Two Numbers (Medium)](https://leetcode.com/problems/add-two-numbers/)

@topic: Linked List
@topic: Math
@topic: Recursion

Constraints:
  - The number of nodes in each linked list is in the range `[1, 100]`.
  - `0 <= Node.val <= 9`
  - It is guaranteed that the list represents a number that does not have leading zeros.
*/

#include "structs/LinkedList.hpp"

class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto fake = ListNode();
        auto curr = &fake;
        auto carry = 0;
        while (l1 || l2 || carry) {
            if (l1) {
                carry += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                carry += l2->val;
                l2 = l2->next;
            }
            curr->next = new ListNode(carry % 10);
            curr = curr->next;
            carry /= 10;
        }
        return fake.next;
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
        {of({2, 4, 3}), of({5, 6, 4}), of({7, 0, 8})},
        {of({0}), of({0}), of({0})},
        {of({9, 9, 9, 9, 9, 9, 9}), of({9, 9, 9, 9}), of({8, 9, 9, 9, 0, 0, 0, 1})},
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
