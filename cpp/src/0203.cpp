/*
[203. Remove Linked List Elements (Easy)](https://leetcode.com/problems/remove-linked-list-elements/)

@topic: Linked List
@topic: Recursion

Constraints:
  - The number of nodes in the list is in the range `[0, 10^4]`.
  - `1 <= Node.val <= 50`
  - `0 <= val <= 50`
*/

#include "structs/LinkedList.hpp"

class Solution {
   public:
    ListNode* removeElements(ListNode* head, int val) {
        auto fake = ListNode(0, head);
        auto curr = &fake;
        while (curr->next) {
            if (curr->next->val == val) {
                auto next = curr->next;
                curr->next = next->next;
                delete next;
            } else {
                curr = curr->next;
            }
        }
        return fake.next;
    }

    // ListNode* removeElements(ListNode* head, int val) {
    //     if (!head) return head;
    //     head->next = removeElements(head->next, val);
    //     if (head->val == val) {
    //         auto next = head->next;
    //         delete head;
    //         return next;
    //     } else {
    //         return head;
    //     }
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

    vector<tuple<ListNode*, int, ListNode*>> CASES = {
        {of({1, 2, 6, 3, 4, 5, 6}), 6, of({1, 2, 3, 4, 5})},
        {of({}), 1, of({})},
        {of({7, 7, 7, 7}), 7, of({})},
    };

    for (auto& [head, val, excepted] : CASES) {
        assert(eq(o.removeElements(head, val), excepted));
    }

    auto start = system_clock::now();
    for (auto i = 0; i < 100000; ++i) {
        o.removeElements(of({1, 2, 6, 3, 4, 5, 6}), 6);
        o.removeElements(of({}), 1);
        o.removeElements(of({7, 7, 7, 7}), 7);
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
