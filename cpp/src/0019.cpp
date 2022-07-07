/*
[19. Remove Nth Node From End of List (Medium)](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)

@topic: Linked List
@topic: Two Pointers

Constraints:
  - The number of nodes in the list is `sz`.
  - `1 <= sz <= 30`
  - `0 <= Node.val <= 100`
  - `1 <= n <= sz`
*/

#include "structs/LinkedList.hpp"

class Solution {
   public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto fake = ListNode(0, head);
        auto slow = &fake;
        auto fast = head;
        while (n--) fast = fast->next;
        while (fast) {
            slow = slow->next;
            fast = fast->next;
        }
        auto next = slow->next;
        slow->next = next->next;
        delete next;
        return fake.next;
    }

    /* ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (dfs(head, n) == n) {
            auto next = head->next;
            head->next = next;
            delete head;
            return next;
        } else {
            return head;
        }
    }

   private:
    int dfs(ListNode* head, int n) {
        if (!head) return 0;
        int x = dfs(head->next, n);
        if (x == n) {
            auto next = head->next;
            head->next = next->next;
            delete next;
        }
        return x + 1;
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

    vector<tuple<ListNode*, int, ListNode*>> CASES = {
        {of({1, 2, 3, 4, 5}), 2, of({1, 2, 3, 5})},
        {of({1}), 1, of({})},
        {of({1, 2}), 1, of({1})},
    };

    for (auto& [head, n, excepted] : CASES) {
        assert(eq(o.removeNthFromEnd(head, n), excepted));
    }

    auto start = system_clock::now();
    for (auto i = 0; i < 100000; ++i) {
        o.removeNthFromEnd(of({1, 2, 3, 4, 5}), 2);
        o.removeNthFromEnd(of({1}), 1);
        o.removeNthFromEnd(of({1, 2}), 1);
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
