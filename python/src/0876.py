from typing import Optional

from structs.ListNode import ListNode, create


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        fast = slow = head
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
        return slow


if __name__ == '__main__':
    import unittest

    CASES = (
        (create(1, 2, 3, 4, 5), create(3, 4, 5)),
        (create(1, 2, 3, 4, 5, 6), create(4, 5, 6)),
    )

    class Test(unittest.TestCase):
        def test(self):
            middleNode = Solution().middleNode
            for head, excepted in CASES:
                actual = middleNode(head)
                self.assertEqual(actual, excepted)

    unittest.main()
