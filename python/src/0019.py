from typing import Optional
from structs.ListNode import ListNode, create


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:

    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        fake = ListNode(0, head)
        slow = fake
        fast = head
        for _ in range(n):
            fast = fast.next
        while fast:
            slow = slow.next
            fast = fast.next
        slow.next = slow.next.next
        return fake.next

    # def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
    #     return head.next if self.__dfs(head, n) == n else head

    # def __dfs(self, head: Optional[ListNode], n: int):
    #     if not head:
    #         return 0
    #     x = self.__dfs(head.next, n)
    #     if x == n:
    #         head.next = head.next.next
    #     return x + 1


if __name__ == '__main__':
    import unittest

    CASES = (
        (create(1, 2, 3, 4, 5), 2, create(1, 2, 3, 5)),
        (create(1), 1, None),
        (create(1, 2), 1, create(1)),
    )

    class Test(unittest.TestCase):

        def test(self):
            removeNthFromEnd = Solution().removeNthFromEnd
            for head, n, excepted in CASES:
                actual = removeNthFromEnd(head, n)
                self.assertEqual(actual, excepted)

    unittest.main()
