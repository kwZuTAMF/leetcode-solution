from typing import Optional

from structs.ListNode import ListNode, create


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        fake = tail = ListNode(0, head)
        while tail.next:
            if tail.next.val == val:
                tail.next = tail.next.next
            else:
                tail = tail.next
        return fake.next


if __name__ == '__main__':
    import unittest

    CASES = (
        (create(1, 2, 6, 3, 4, 5, 6), 6, create(1, 2, 3, 4, 5)),
        (None, 1, None),
        (create(7, 7, 7, 7), 7, None),
    )

    class Test(unittest.TestCase):
        def test(self):
            removeElements = Solution().removeElements
            for head, val, excepted in CASES:
                actual = removeElements(head, val)
                self.assertEqual(actual, excepted)

    unittest.main()
