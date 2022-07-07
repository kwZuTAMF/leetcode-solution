from collections import deque
from typing import Optional

from structs.ListNode import ListNode, create


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        stack = deque()
        fast = slow = head
        while fast and fast.next:
            stack.append(slow.val)
            slow = slow.next
            fast = fast.next.next
        if fast:
            slow = slow.next
        while slow:
            if stack.pop() != slow.val:
                return False
            slow = slow.next
        return True

    # def isPalindrome(self, head: ListNode) -> bool:
    #     if not head or not head.next:
    #         return True
    #     fast = slow = head
    #     while fast and fast.next:
    #         slow = slow.next
    #         fast = fast.next.next
    #     left = head
    #     right = slow = self.reverse(slow.next if fast else slow)
    #     while right and left.val == right.val:
    #         left = left.next
    #         right = right.next
    #     self.reverse(slow)
    #     return right is None

    # def reverse(self, head: Optional[ListNode]) -> Optional[ListNode]:
    #     prev = None
    #     walk = head
    #     while walk:
    #         next = walk.next
    #         walk.next = prev
    #         prev = walk
    #         walk = next
    #     return prev


if __name__ == '__main__':
    import unittest

    CASES = (
        (create(1, 2, 3, 2, 1), True),
        (create(1, 2, 2, 1), True),
        (create(1, 2), False),
        (create(1), True),
        (None, True),
    )

    class Test(unittest.TestCase):
        def test(self):
            isPalindrome = Solution().isPalindrome
            for head, excepted in CASES:
                actual = isPalindrome(head)
                self.assertEqual(actual, excepted)

    unittest.main()
