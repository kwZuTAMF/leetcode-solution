/*
[21. Merge Two Sorted Lists (Easy)](https://leetcode.com/problems/merge-two-sorted-lists/)

@topic: Linked List
@topic: Recursion

Constraints:
  - The number of nodes in both lists is in the range `[0, 50]`.
  - `-100 <= Node.val <= 100`
  - Both `list1` and `list2` are sorted in **non-decreasing** order.
*/

#include "structs/LinkedList.hpp"

class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        auto fake = ListNode();
        auto curr = &fake;
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        curr->next = list1 ? list1 : list2;
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

    vector<tuple<ListNode*, ListNode*, ListNode*>> CASES = {
        {of({1, 2, 4}), of({1, 3, 4}), of({1, 1, 2, 3, 4, 4})},
        {of({}), of({}), of({})},
        {of({}), of({0}), of({0})},
    };

    for (auto& [list1, list2, excepted] : CASES) {
        assert(eq(o.mergeTwoLists(list1, list2), excepted));
    }

    auto start = system_clock::now();
    for (auto i = 0; i < 100000; ++i) {
        o.mergeTwoLists(of({1, 2, 4}), of({1, 3, 4}));
        o.mergeTwoLists(of({}), of({}));
        o.mergeTwoLists(of({}), of({0}));
    }

    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
