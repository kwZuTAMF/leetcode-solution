/*
[234. Palindrome Linked List (Easy)](https://leetcode.com/problems/palindrome-linked-list/)

@topic: Linked List
@topic: Two Pointers
@topic: Stack
@topic: Recursion

Constraints:
  - The number of nodes in the list is in the range `[1, 10^5]`.
  - `0 <= Node.val <= 9`
*/

#include <stack>

#include "structs/LinkedList.hpp"

using std::stack;

class Solution {
   public:
    bool isPalindrome(ListNode* head) {
        if (!head->next) return true;
        stack<int> stk;
        auto slow = head;
        auto fast = head;
        while (fast && fast->next) {
            stk.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast) {
            slow = slow->next;
        }
        while (slow) {
            if (stk.top() != slow->val) {
                return false;
            }
            stk.pop();
            slow = slow->next;
        }
        return true;
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
        {of({1, 2, 2, 1}), true},
        {of({1, 2}), false},
    };

    for (auto& [head, excepted] : CASES) {
        assert(o.isPalindrome(head) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [head, _] : CASES) {
        for (auto i = 0; i < 100000; ++i) {
            o.isPalindrome(head);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
