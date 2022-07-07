/*
[82. Remove Duplicates from Sorted List II (Medium)](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/)

@topic: Linked List
@topic: Two Pointers

Constraints:
  - The number of nodes in the list is in the range `[0, 300]`.
  - `-100 <= Node.val <= 100`
  - The list is guaranteed to be **sorted** in ascending order.
*/

#include "structs/LinkedList.hpp"

class Solution {
   public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        auto fake = ListNode(0, head);
        auto slow = &fake;
        auto fast = head;
        while (fast) {
            while (fast->next && fast->val == fast->next->val) {
                auto prev = fast;
                fast = fast->next;
                delete prev;
            }
            if (slow->next != fast) {
                slow->next = fast->next;
            } else {
                slow = slow->next;
            }
            fast = fast->next;
        }
        return fake.next;
    }

    // ListNode* deleteDuplicates(ListNode* head) {
    //     if (!head || !head->next) return head;
    //     auto fake = ListNode(0, head);
    //     auto curr = &fake;
    //     while (curr->next && curr->next->next) {
    //         auto val = curr->next->val;
    //         if (val != curr->next->next->val) {
    //             curr = curr->next;
    //         } else {
    //             while (curr->next && curr->next->val == val) {
    //                 auto next = curr->next;
    //                 curr->next = next->next;
    //                 delete next;
    //             }
    //         }
    //     }
    //     return fake.next;
    // }
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
        {of({1, 2, 3, 3, 4, 4, 5}), of({1, 2, 5})},
        {of({1, 1, 1, 2, 3}), of({2, 3})},
    };

    for (auto& [head, excepted] : CASES) {
        assert(eq(o.deleteDuplicates(head), excepted));
    }

    auto start = system_clock::now();
    for (auto i = 0; i < 100000; ++i) {
        o.deleteDuplicates(of({1, 2, 3, 3, 4, 4, 5}));
        o.deleteDuplicates(of({1, 1, 1, 2, 3}));
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
