/*
[86. Partition List (Medium)](https://leetcode.com/problems/partition-list/)

@topic: Linked List
@topic: Two Pointers

Constraints:
  - The number of nodes in the list is in the range `[0, 200]`.
  - `-100 <= Node.val <= 100`
  - `-200 <= x <= 200`
*/

#include "structs/LinkedList.hpp"

class Solution {
   public:
    ListNode* partition(ListNode* head, int x) {
        ListNode lt = ListNode(), ge = ListNode(), *p = &lt, *q = &ge;
        while (head) {
            if (head->val < x) {
                p->next = head;
                p = p->next;
            } else {
                q->next = head;
                q = q->next;
            }
            head = head->next;
        }
        q->next = nullptr;
        p->next = ge.next;
        return lt.next;
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

    vector<tuple<ListNode*, int, ListNode*>> CASES = {
        {of({1, 4, 3, 2, 5, 2}), 3, of({1, 2, 2, 4, 3, 5})},
        {of({2, 1}), 2, of({1, 2})},
    };

    for (auto& [head, x, excepted] : CASES) {
        assert(eq(o.partition(head, x), excepted));
    }

    auto start = system_clock::now();
    for (auto i = 0; i < 100000; ++i) {
        o.partition(of({1, 4, 3, 2, 5, 2}), 3);
        o.partition(of({2, 1}), 2);
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
