/*
[92. Reverse Linked List II (Medium)](https://leetcode.com/problems/reverse-linked-list-ii/)

@topic: Linked List

Constraints:
  - The number of nodes in the list is `n`.
  - `1 <= n <= 500`
  - `-500 <= Node.val <= 500`
  - `1 <= left <= right <= n`
*/

#include "structs/LinkedList.hpp"

class Solution {
   public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;
        auto fake = ListNode(0, head);
        auto prev = &fake;
        auto step = right - left;
        while (--left) prev = prev->next;
        auto curr = prev->next;
        while (step--) {
            auto next = curr->next;
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }
        return fake.next;
    }

    /* ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;
        auto fake = ListNode(0, head);
        auto slow = &fake;
        auto fast = head;
        while (--left) slow = slow->next;
        while (right--) fast = fast->next;
        slow->next = reverse(slow->next, fast);
        return fake.next;
    }

   private:
    ListNode* reverse(ListNode* head, ListNode* last) {
        auto prev = last;
        while (head != last) {
            auto next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    } */
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

    vector<tuple<ListNode*, int, int, ListNode*>> CASES = {
        {of({1, 2, 3, 4, 5}), 1, 5, of({5, 4, 3, 2, 1})},
        {of({1, 2, 3, 4, 5}), 2, 4, of({1, 4, 3, 2, 5})},
        {of({5}), 1, 1, of({5})},
    };

    for (auto& [head, left, right, excepted] : CASES) {
        assert(eq(o.reverseBetween(head, left, right), excepted));
    }

    auto start = system_clock::now();
    for (auto i = 0; i < 100000; ++i) {
        o.reverseBetween(of({1, 2, 3, 4, 5}), 1, 1);
        o.reverseBetween(of({5}), 1, 1);
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
