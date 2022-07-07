from typing import Optional

from structs.ListNode import ListNode, create


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        fake = walk = ListNode()
        while list1 and list2:
            if list1.val <= list2.val:
                walk.next = list1
                list1 = list1.next
            else:
                walk.next = list2
                list2 = list2.next
            walk = walk.next
        walk.next = list1 or list2
        return fake.next


if __name__ == '__main__':
    import unittest

    CASES = (
        (create(1, 2, 4), create(1, 3, 4), create(1, 1, 2, 3, 4, 4)),
        (None, None, None),
        (None, ListNode(0), ListNode(0)),
    )

    class Test(unittest.TestCase):
        def test(self):
            mergeTwoLists = Solution().mergeTwoLists
            for l1, l2, excepted in CASES:
                actual = mergeTwoLists(l1, l2)
                self.assertEqual(actual, excepted)

    unittest.main()
