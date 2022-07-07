/*
[876. Middle of the Linked List (Easy)](https://leetcode.com/problems/middle-of-the-linked-list/)

@topic: Linked List
@topic: Two Pointers

Constraints:
  - The number of nodes in the list is in the range `[1, 100]`.
  - `1 <= Node.val <= 100`
*/

#include "structs/LinkedList.hpp"

class Solution {
   public:
    ListNode* middleNode(ListNode* head) {
        auto slow = head;
        auto fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
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
        {of({1, 2, 3, 4, 5}), of({3, 4, 5})},
        {of({1, 2, 3, 4, 5, 6}), of({4, 5, 6})},
    };

    for (auto& [head, excepted] : CASES) {
        assert(eq(o.middleNode(head), excepted));
    }

    auto start = system_clock::now();
    for (auto& [head, _] : CASES) {
        for (auto i = 0; i < 100000; ++i) {
            o.middleNode(head);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
