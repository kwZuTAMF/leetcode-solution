/*
[1721. Swapping Nodes in a Linked List (Medium)](https://leetcode.com/problems/swapping-nodes-in-a-linked-list/)

@topic: Linked List
@topic: Two Pointers

Constraints:
  - The number of nodes in the list is `n`.
  - `1 <= k <= n <= 10^5`
  - `0 <= Node.val <= 100`
*/

#include "structs/LinkedList.hpp"

using std::swap;

class Solution {
   public:
    ListNode* swapNodes(ListNode* head, int k) {
        if (k == 1) return head;
        auto slow = head;
        auto fast = head;
        while (--k) fast = fast->next;
        auto curr = fast;
        while (curr->next) {
            curr = curr->next;
            slow = slow->next;
        }
        swap(slow->val, fast->val);
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

    vector<tuple<ListNode*, int, ListNode*>> CASES = {
        {of({1, 2, 3, 4, 5}), 2, of({1, 4, 3, 2, 5})},
        {of({7, 9, 6, 6, 7, 8, 3, 0, 9, 5}), 5, of({7, 9, 6, 6, 8, 7, 3, 0, 9, 5})},
    };

    for (auto& [head, k, excepted] : CASES) {
        assert(eq(o.swapNodes(head, k), excepted));
    }

    auto start = system_clock::now();
    for (auto i = 0; i < 100000; ++i) {
        o.swapNodes(of({1, 2, 3, 4, 5}), 2);
        o.swapNodes(of({7, 9, 6, 6, 7, 8, 3, 0, 9, 5}), 5);
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
