/*
[160. Intersection of Two Linked Lists (Easy)](https://leetcode.com/problems/intersection-of-two-linked-lists/)

@topic: Hash Table
@topic: Linked List
@topic: Two Pointers

Constraints:
  - The number of nodes of `listA` is in the `m`.
  - The number of nodes of `listB` is in the `n`.
  - `1 <= m, n <= 3 * 10^4`
  - `1 <= Node.val <= 10^5`
  - `0 <= skipA < m`
  - `0 <= skipB < n`
  - `intersectVal` is `0` if `listA` and `listB` do not intersect.
  - `intersectVal == listA[skipA] == listB[skipB]` if `listA` and `listB` intersect.
*/

#include "structs/LinkedList.hpp"

class Solution {
   public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;
        auto p = headA;
        auto q = headB;
        while (p != q) {
            p = p ? p->next : headB;
            q = q ? q->next : headA;
        }
        return p;
    }
};
