/*
[148. Sort List (Medium)](https://leetcode.com/problems/sort-list/)

@topic: Linked List
@topic: Two Pointers
@topic: Divide and Conquer
@topic: Sorting
@topic: Merge Sort

Constraints:
  - The number of nodes in the list is in the range `[0, 5 * 10^4]`.
  - `-10^5 <= Node.val <= 10^5`
*/

#include "structs/LinkedList.hpp"

class Solution {
   public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        auto size = 0;
        auto last = head;
        while (last) {
            ++size;
            last = last->next;
        }
        auto fake = ListNode(0, head);
        for (auto step = 1; step < size; step <<= 1) {
            auto prev = &fake;
            auto curr = fake.next;
            while (curr) {
                auto i = step;
                auto p = curr;
                for (; curr && i; --i) curr = curr->next;
                if (i) break;
                auto j = step;
                auto q = curr;
                for (; curr && j; --j) curr = curr->next;
                auto m = step;
                auto n = step - j;
                while (m && n) {
                    if (p->val <= q->val) {
                        prev->next = p;
                        p = p->next;
                        --m;
                    } else {
                        prev->next = q;
                        q = q->next;
                        --n;
                    }
                    prev = prev->next;
                }
                prev->next = p ? p : q;
                for (; m > 0 || n > 0; --m, --n) prev = prev->next;
                prev->next = curr;
            }
        }
        return fake.next;
    }

    /* ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        auto prev = head;
        auto slow = head;
        auto fast = head;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr;
        return merge(sortList(head), sortList(slow));
    }

   private:
    ListNode* merge(ListNode* p, ListNode* q) {
        auto fake = ListNode();
        auto curr = &fake;
        while (p && q) {
            if (p->val <= q->val) {
                curr->next = p;
                p = p->next;
            } else {
                curr->next = q;
                q = q->next;
            }
            curr = curr->next;
        }
        curr->next = p ? p : q;
        return fake.next;
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

    vector<tuple<ListNode*, ListNode*>> CASES = {
        {of({4, 2, 1, 3}), of({1, 2, 3, 4})},
        {of({-1, 5, 3, 4, 0}), of({-1, 0, 3, 4, 5})},
        {nullptr, nullptr},
    };

    for (auto& [head, excepted] : CASES) {
        assert(eq(o.sortList(head), excepted));
    }

    auto start = system_clock::now();
    for (auto i = 0; i < 100000; ++i) {
        o.sortList(of({4, 2, 1, 3}));
        o.sortList(of({-1, 5, 3, 4, 0}));
        o.sortList(nullptr);
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
