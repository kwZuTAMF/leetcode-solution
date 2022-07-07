/*
[83. Remove Duplicates from Sorted List (Easy)](https://leetcode.com/problems/remove-duplicates-from-sorted-list/)

@topic: Linked List

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
        auto curr = head;
        while (curr->next) {
            auto next = curr->next;
            if (curr->val == next->val) {
                curr->next = next->next;
                delete next;
            } else {
                curr = curr->next;
            }
        }
        return head;
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
        {of({1, 1, 2}), of({1, 2})},
        {of({1, 1, 2, 3, 3}), of({1, 2, 3})},
    };

    for (auto& [head, excepted] : CASES) {
        assert(eq(o.deleteDuplicates(head), excepted));
    }

    auto start = system_clock::now();
    for (auto i = 0; i < 100000; ++i) {
        o.deleteDuplicates(of({1, 1, 2}));
        o.deleteDuplicates(of({1, 1, 2, 3, 3}));
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
