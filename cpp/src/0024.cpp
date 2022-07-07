/*
[24. Swap Nodes in Pairs (Medium)](https://leetcode.com/problems/swap-nodes-in-pairs/)

@topic: Linked List
@topic: Recursion

Constraints:
  - The number of nodes in the&nbsp;list&nbsp;is in the range `[0, 100]`.
  - `0 <= Node.val <= 100`
*/

#include "structs/LinkedList.hpp"

class Solution {
   public:
    ListNode* swapPairs(ListNode* head) {
        auto fake = ListNode(0, head);
        auto curr = &fake;
        while (curr->next && curr->next->next) {
            auto next = curr->next;
            head = next->next->next;
            curr->next = next->next;
            next->next->next = next;
            next->next = head;
            curr = next;
        }
        return fake.next;
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
        {of({1, 2, 3, 4}), of({2, 1, 4, 3})},
        {of({}), of({})},
        {of({1}), of({1})},
    };

    for (auto& [head, excepted] : CASES) {
        assert(eq(o.swapPairs(head), excepted));
    }

    auto start = system_clock::now();
    for (auto i = 0; i < 100000; ++i) {
        o.swapPairs(of({1, 2, 3, 4}));
        o.swapPairs(of({}));
        o.swapPairs(of({1}));
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
