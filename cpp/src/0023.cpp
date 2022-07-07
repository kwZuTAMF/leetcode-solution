/*
[23. Merge k Sorted Lists (Hard)](https://leetcode.com/problems/merge-k-sorted-lists/)

@topic: Linked List
@topic: Divide and Conquer
@topic: Heap (Priority Queue)
@topic: Merge Sort

Constraints:
  - `k == lists.length`
  - `0 <= k <= 10^4`
  - `0 <= lists[i].length <= 500`
  - `-10^4 <= lists[i][j] <= 10^4`
  - `lists[i]` is sorted in **ascending order**.
  - The sum of `lists[i].length` will not exceed `10^4`.
*/

#include <vector>

#include "structs/LinkedList.hpp"

using std::vector;

class Solution {
   public:
    // ListNode* mergeKLists(vector<ListNode*>& lists) {
    //     int k = lists.size();
    //     if (k == 0) return nullptr;
    //     for (int step = 1; step < k; step <<= 1) {
    //         for (int i = 0; i + step < k; i += step << 1) {
    //             lists[i] = merge(lists[i], lists[i + step]);
    //         }
    //     }
    //     return lists[0];
    // }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        switch (lists.size()) {
            case 0:
                return nullptr;
            case 1:
                return lists[0];
            default:
                return sort(lists, 0, lists.size() - 1);
        }
    }

   private:
    ListNode* sort(vector<ListNode*>& lists, int left, int right) {
        if (left == right) return lists[left];
        int m = left + ((right - left) >> 1);
        return merge(sort(lists, left, m), sort(lists, m + 1, right));
    }

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
    }
};

#include <cassert>
#include <chrono>
#include <iostream>

using std::tuple;
using std::chrono::duration_cast;
using std::chrono::microseconds;
using std::chrono::system_clock;

int main() {
    using namespace LinkedList;

    Solution o;

    vector<tuple<vector<ListNode*>, ListNode*>> CASES = {
        {{of({1, 4, 5}), of({1, 3, 4}), of({2, 6})}, of({1, 1, 2, 3, 4, 4, 5, 6})},
        {{}, nullptr},
        {{nullptr}, nullptr},
    };

    for (auto& [lists, excepted] : CASES) {
        assert(eq(o.mergeKLists(lists), excepted));
    }

    auto start = system_clock::now();
    for (auto i = 0; i < 100000; ++i) {
        vector<ListNode*> lists = {of({1, 4, 5}), of({1, 3, 4}), of({2, 6})};
        o.mergeKLists(lists);
        lists = {};
        o.mergeKLists(lists);
        lists = {nullptr};
        o.mergeKLists(lists);
    }

    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
