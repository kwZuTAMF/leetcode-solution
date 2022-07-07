/*
[206. Reverse Linked List (Easy)](https://leetcode.com/problems/reverse-linked-list/)

@topic: Linked List
@topic: Recursion

Constraints:
  - The number of nodes in the list is the range `[0, 5000]`.
  - `-5000 <= Node.val <= 5000`
*/

#include "structs/LinkedList.hpp"

class Solution {
   public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr, *next;
        while (head) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

    // ListNode* reverseList(ListNode* head) {
    //     if (!head || !head->next) return head;
    //     auto last = reverseList(head->next);
    //     head->next->next = head;
    //     head->next = nullptr;
    //     return last;
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

    vector<tuple<ListNode*, ListNode*>> CASES = {
        {of({1, 2, 3, 4, 5}), of({5, 4, 3, 2, 1})},
        {of({1, 2}), of({2, 1})},
        {of({}), of({})},
    };

    for (auto& [head, excepted] : CASES) {
        assert(eq(o.reverseList(head), excepted));
    }

    auto start = system_clock::now();
    for (auto i = 0; i < 100000; ++i) {
        o.reverseList(of({1, 2, 3, 4, 5}));
        o.reverseList(of({1, 2}));
        o.reverseList(of({}));
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
