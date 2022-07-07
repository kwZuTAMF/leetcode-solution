/*
[143. Reorder List (Medium)](https://leetcode.com/problems/reorder-list/)

@topic: Linked List
@topic: Two Pointers
@topic: Stack
@topic: Recursion

Constraints:
  - The number of nodes in the list is in the range `[1, 5 * 10^4]`.
  - `1 <= Node.val <= 1000`
*/

#include "structs/LinkedList.hpp"

class Solution {
   public:
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* last = nullptr;
        ListNode* next = slow->next;
        slow->next = nullptr;
        slow = next;
        while (slow) {
            next = slow->next;
            slow->next = last;
            last = slow;
            slow = next;
        }
        while (last) {
            next = last->next;
            last->next = head->next;
            head->next = last;
            head = last->next;
            last = next;
        }
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
        {of({1, 2, 3}), of({1, 3, 2})},
        {of({1, 2, 3, 4}), of({1, 4, 2, 3})},
        {of({1, 2, 3, 4, 5}), of({1, 5, 2, 4, 3})},
    };

    for (auto& [head, excepted] : CASES) {
        o.reorderList(head);
        assert(eq(head, excepted));
    }

    auto start = system_clock::now();
    for (auto i = 0; i < 100000; ++i) {
        o.reorderList(of({1, 2, 3, 4}));
        o.reorderList(of({1, 2, 3, 4, 5}));
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
