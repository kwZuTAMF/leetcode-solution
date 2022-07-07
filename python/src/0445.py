from typing import Optional

from structs.ListNode import ListNode, create

from collections import deque


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:

    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        s1, s2 = deque(), deque()
        p, q = l1, l2
        while p:
            s1.append(p.val)
            p = p.next
        while q:
            s2.append(q.val)
            q = q.next
        carry, prev = 0, None
        while s1 or s2 or carry:
            if s1:
                carry += s1.pop()
            if s2:
                carry += s2.pop()
            curr = ListNode(carry % 10, prev)
            carry //= 10
            prev = curr
        return prev


if __name__ == '__main__':
    import unittest

    CASES = (
        (create(7, 2, 4, 3), create(5, 6, 4), create(7, 8, 0, 7)),
        (create(2, 4, 3), create(5, 6, 4), create(8, 0, 7)),
        (create(0), create(0), create(0)),
        (None, None, None),
    )

    class Test(unittest.TestCase):

        def test(self):
            addTwoNumbers = Solution().addTwoNumbers
            for l1, l2, excepted in CASES:
                actual = addTwoNumbers(l1, l2)
                self.assertEqual(actual, excepted)

    unittest.main()
