from typing import Optional

from structs.ListNode import ListNode, create


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head
        walk = head
        while walk.next:
            if walk.val == walk.next.val:
                walk.next = walk.next.next
            else:
                walk = walk.next
        return head


if __name__ == '__main__':
    import unittest

    CASES = (
        (create(1, 1, 2), create(1, 2)),
        (create(1, 1, 2, 3, 3), create(1, 2, 3)),
    )

    class Test(unittest.TestCase):
        def test(self):
            deleteDuplicates = Solution().deleteDuplicates
            for head, excepted in CASES:
                actual = deleteDuplicates(head)
                self.assertEqual(actual, excepted)

    unittest.main()
