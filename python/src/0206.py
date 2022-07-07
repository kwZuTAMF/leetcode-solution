from typing import Optional

from structs.ListNode import ListNode, create


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev = None
        walk = head
        while walk:
            next = walk.next
            walk.next = prev
            prev = walk
            walk = next
        return prev

    # def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
    #     fake = ListNode()
    #     walk = head
    #     while walk:
    #         next = walk.next
    #         walk.next = fake.next
    #         fake.next = walk
    #         walk = next
    #     return fake.next

    # def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
    #     if not head or not head.next:
    #         return head
    #     tail = self.reverseList(head.next)
    #     head.next.next = head
    #     head.next = None
    #     return tail


if __name__ == '__main__':
    import unittest

    CASES = (
        (create(1, 2, 3, 4, 5), create(5, 4, 3, 2, 1)),
        (create(1, 2), create(2, 1)),
        (None, None),
    )

    class Test(unittest.TestCase):

        def test(self):
            reverseList = Solution().reverseList
            for head, excepted in CASES:
                actual = reverseList(head)
                self.assertEqual(actual, excepted)

    unittest.main()
