/*
[237. Delete Node in a Linked List (Easy)](https://leetcode.com/problems/delete-node-in-a-linked-list/)

@topic: Linked List

Constraints:
  - The number of the nodes in the given list is in the range `[2, 1000]`.
  - `-1000 <= Node.val <= 1000`
  - The value of each node in the list is **unique**.
  - The `node` to be deleted is **in the list** and is **not a tail** node
*/

#include "structs/LinkedList.hpp"

class Solution {
   public:
    void deleteNode(ListNode* node) {
        *node = *node->next;
    }
};
