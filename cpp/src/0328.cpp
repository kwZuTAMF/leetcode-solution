/*
[328. Odd Even Linked List (Medium)](https://leetcode.com/problems/odd-even-linked-list/)

@topic: Linked List

Constraints:
  - The number of nodes in the linked list is in the range `[0, 10^4]`.
  - `-10^6 <= Node.val <= 10^6`
*/

#include "structs/LinkedList.hpp"

class Solution {
   public:
    // TODO: improve
    ListNode* oddEvenList(ListNode* head) {
        ListNode odd = ListNode(), even = ListNode(), *p = &odd, *q = &even;
        for (int i = 1; head; ++i) {
            if (i & 1) {
                p->next = head;
                p = p->next;
            } else {
                q->next = head;
                q = q->next;
            }
            head = head->next;
        }
        q->next = nullptr;
        p->next = even.next;
        return odd.next;
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

    vector<tuple<ListNode*, ListNode*>> CASES = {
        {of({1, 2, 3, 4, 5}), of({1, 3, 5, 2, 4})},
        {of({2, 1, 3, 5, 6, 4, 7}), of({2, 3, 6, 7, 1, 5, 4})},
    };

    for (auto& [head, excepted] : CASES) {
        assert(eq(o.oddEvenList(head), excepted));
    }

    auto start = system_clock::now();
    for (auto i = 0; i < 100000; ++i) {
        o.oddEvenList(of({1, 2, 3, 4, 5}));
        o.oddEvenList(of({2, 1, 3, 5, 6, 4, 7}));
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
