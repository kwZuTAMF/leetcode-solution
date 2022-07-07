/*
[25. Reverse Nodes in k-Group (Hard)](https://leetcode.com/problems/reverse-nodes-in-k-group/)

@topic: Linked List
@topic: Recursion

Constraints:
  - The number of nodes in the list is `n`.
  - `1 <= k <= n <= 5000`
  - `0 <= Node.val <= 1000`
*/

#include "structs/LinkedList.hpp"

class Solution {
   public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) return head;
        auto fake = ListNode(0, head);
        auto prev = &fake;
        auto slow = head;
        auto fast = head;
        while (fast) {
            int i = -1;
            while (++i < k && fast) fast = fast->next;
            if (i == k) {
                prev->next = reverse(slow, fast);
                prev = slow;
                slow = fast;
            }
        }
        return fake.next;
    }

   private:
    ListNode* reverse(ListNode* head, ListNode* last) {
        auto prev = last;
        while (head != last) {
            auto next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
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
        {of({1, 2, 3, 4}), 2, of({2, 1, 4, 3})},
        {of({1, 2, 3, 4, 5}), 2, of({2, 1, 4, 3, 5})},
        {of({1, 2, 3, 4, 5}), 3, of({3, 2, 1, 4, 5})},
    };

    for (auto& [head, k, excepted] : CASES) {
        assert(eq(o.reverseKGroup(head, k), excepted));
    }

    auto start = system_clock::now();
    for (auto i = 0; i < 100000; ++i) {
        o.reverseKGroup(of({1, 2, 3, 4, 5}), 2);
        o.reverseKGroup(of({1, 2, 3, 4, 5}), 3);
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
