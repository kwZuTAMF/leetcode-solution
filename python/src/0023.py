from heapq import heappop, heappush
from typing import Optional

from structs.ListNode import ListNode, create


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: list[Optional[ListNode]]) -> Optional[ListNode]:
        match lists:
            case []:
                return
            case [x]:
                return x
            case _:
                fake = walk = ListNode()
                heap = [(x.val, i) for i, x in enumerate(lists) if x]
                while heap:
                    i = heappop(heap)[1]
                    walk.next = walk = lists[i]
                    lists[i] = lists[i].next
                    if lists[i]:
                        heappush(heap, (lists[i].val, i))
                return fake.next

    # def mergeKLists(self, lists: list[Optional[ListNode]]) -> Optional[ListNode]:
    #     match lists:
    #         case []:
    #             return
    #         case [x]:
    #             return x
    #         case _:
    #             m = len(lists) >> 1
    #             return self.mergeTwoLists(self.mergeKLists(lists[:m]), self.mergeKLists(lists[m:]))

    # def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
    #     fake = walk = ListNode()
    #     while list1 and list2:
    #         if list1.val <= list2.val:
    #             walk.next = list1
    #             list1 = list1.next
    #         else:
    #             walk.next = list2
    #             list2 = list2.next
    #         walk = walk.next
    #     walk.next = list1 or list2
    #     return fake.next


if __name__ == '__main__':
    import unittest

    CASES = (
        ([create(3, 3, 3), None, create(3, 3, 3)], create(3, 3, 3, 3, 3, 3)),
        ([create(1, 4, 5), create(1, 3, 4), create(2, 6)], create(1, 1, 2, 3, 4, 4, 5, 6)),
        ([], None),
        ([None], None),
    )

    class Test(unittest.TestCase):
        def test(self):
            mergeKLists = Solution().mergeKLists
            for lists, excepted in CASES:
                actual = mergeKLists(lists)
                self.assertEqual(actual, excepted)

    unittest.main()

    from timeit import timeit

    mergeKLists = Solution().mergeKLists
    for lists, _ in CASES:
        print(timeit(lambda: mergeKLists(lists), number=100000))
