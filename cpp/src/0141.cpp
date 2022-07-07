/*
[141. Linked List Cycle (Easy)](https://leetcode.com/problems/linked-list-cycle/)

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
    bool hasCycle(ListNode* head) {
        auto slow = head;
        auto fast = slow;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                return true;
            }
        }
        return false;
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

    vector<tuple<ListNode*, bool>> CASES = {
        {cycle({3, 2, 0, -4}, 1), true},
        {cycle({1, 2}, 0), true},
        {cycle({1}, -1), false},
    };

    for (auto& [head, excepted] : CASES) {
        assert(o.hasCycle(head) == excepted);
    }

    auto start = system_clock::now();
    for (auto i = 0; i < 100000; ++i) {
        o.hasCycle(cycle({3, 2, 0, -4}, 1));
        o.hasCycle(cycle({1, 2}, 0));
        o.hasCycle(cycle({1}, -1));
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
