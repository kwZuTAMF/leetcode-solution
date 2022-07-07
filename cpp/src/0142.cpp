/*
[142. Linked List Cycle II (Medium)](https://leetcode.com/problems/linked-list-cycle-ii/)

@topic: Hash Table
@topic: Linked List
@topic: Two Pointers

Constraints:
  - The number of the nodes in the list is in the range `[0, 10^4]`.
  - `-10^5 <= Node.val <= 10^5`
  - `pos` is `-1` or a **valid index** in the linked-list.
*/

#include "structs/LinkedList.hpp"

class Solution {
   public:
    ListNode* detectCycle(ListNode* head) {
        auto slow = head;
        auto fast = slow;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                fast = head;
                while (fast != slow) {
                    fast = fast->next;
                    slow = slow->next;
                }
                return fast;
            }
        }
        return nullptr;
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
        {cycle({3, 2, 0, -4}, 1), of({2})},
        {cycle({1, 2}, 0), of({1})},
        {cycle({1}, -1), nullptr},
    };

    for (auto& [head, excepted] : CASES) {
        auto node = o.detectCycle(head);
        if (node == nullptr) {
            assert(node == excepted);
        } else {
            assert(node->val == excepted->val);
        }
    }

    auto start = system_clock::now();
    for (auto i = 0; i < 100000; ++i) {
        o.detectCycle(cycle({3, 2, 0, -4}, 1));
        o.detectCycle(cycle({1, 2}, 0));
        o.detectCycle(cycle({1}, -1));
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
