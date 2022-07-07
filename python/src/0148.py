from typing import Optional

from structs.ListNode import ListNode, create


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:

    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head
        size, tail = 0, head
        while tail:
            tail = tail.next
            size += 1
        fake, step = ListNode(0, head), 1
        while step < size:
            prev, curr = fake, fake.next
            while curr:
                i, p = step, curr
                while curr and i:
                    curr = curr.next
                    i -= 1
                if i:
                    break
                j, q = step, curr
                while curr and j:
                    curr = curr.next
                    j -= 1
                m, n = step, step - j
                while m and n:
                    if p.val <= q.val:
                        prev.next = p
                        p = p.next
                        m -= 1
                    else:
                        prev.next = q
                        q = q.next
                        n -= 1
                    prev = prev.next
                else:
                    prev.next = p if m else q
                while m > 0 or n > 0:
                    prev = prev.next
                    m -= 1
                    n -= 1
                else:
                    prev.next = curr
            step <<= 1
        return fake.next

    # def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
    #     if not head or not head.next:
    #         return head
    #     prev = slow = fast = head
    #     while fast and fast.next:
    #         prev = slow
    #         slow = slow.next
    #         fast = fast.next.next
    #     prev.next = None
    #     lst1 = self.sortList(head)
    #     lst2 = self.sortList(slow)
    #     fake = ListNode()
    #     curr = fake
    #     while lst1 and lst2:
    #         if lst1.val <= lst2.val:
    #             curr.next = lst1
    #             lst1 = lst1.next
    #         else:
    #             curr.next = lst2
    #             lst2 = lst2.next
    #         curr = curr.next
    #     else:
    #         curr.next = lst1 or lst2
    #     return fake.next


if __name__ == '__main__':
    import unittest

    CASES = (
        (create(5, 4, 3, 2, 1), create(1, 2, 3, 4, 5)),
        (create(4, 2, 1, 3), create(1, 2, 3, 4)),
        (create(-1, 5, 3, 4, 0), create(-1, 0, 3, 4, 5)),
        (None, None),
    )

    class Test(unittest.TestCase):

        def test(self):
            sortList = Solution().sortList
            for head, excepted in CASES:
                actual = sortList(head)
                self.assertEqual(actual, excepted)

    unittest.main()
