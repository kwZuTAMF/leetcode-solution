/*
[61. Rotate List (Medium)](https://leetcode.com/problems/rotate-list/)

@topic: Linked List
@topic: Two Pointers

Constraints:
  - The number of nodes in the list is in the range `[0, 500]`.
  - `-100 <= Node.val <= 100`
  - `0 <= k <= 2 * 10^9`
*/

#include "structs/LinkedList.hpp"

class Solution {
   public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        auto size = 1;
        auto curr = head;
        while (curr->next) {
            ++size;
            curr = curr->next;
        }
        int step = size - k % size;
        if (step == size) {
            return head;
        }
        curr->next = head;
        while (step--) {
            curr = curr->next;
        }
        head = curr->next;
        curr->next = nullptr;
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
        {of({1, 2, 3, 4, 5}), 2, of({4, 5, 1, 2, 3})},
        {of({0, 1, 2}), 4, of({2, 0, 1})},
    };

    for (auto& [head, k, excepted] : CASES) {
        assert(eq(o.rotateRight(head, k), excepted));
    }

    auto start = system_clock::now();
    for (auto i = 0; i < 100000; ++i) {
        o.rotateRight(of({1, 2, 3, 4, 5}), 2);
        o.rotateRight(of({0, 1, 2}), 4);
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
