from typing import Optional

from structs.ListNode import ListNode, create


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head or not head.next or not k:
            return head
        size, walk = 1, head
        while walk.next:
            walk = walk.next
            size += 1
        if (step := size - k % size) == size:
            return head
        walk.next = head
        while step:
            walk = walk.next
            step -= 1
        head = walk.next
        walk.next = None
        return head


if __name__ == '__main__':
    import unittest
    from timeit import timeit

    CASES = (
        (create(1, 2, 3, 4, 5), 2 + 5, create(4, 5, 1, 2, 3)),
        (create(0, 1, 2), 4, create(2, 0, 1)),
    )

    class Test(unittest.TestCase):

        def test(self):
            rotateRight = Solution().rotateRight
            for head, k, excepted in CASES:
                actual = rotateRight(head, k)
                self.assertEqual(actual, excepted)

    unittest.main()

    rotateRight = Solution().rotateRight
    for head, k, _ in CASES:
        print(timeit(lambda: rotateRight(head, k), number=1000000))
