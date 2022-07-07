from structs.ListNode import ListNode, create


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        n, p = 0, head
        while p:
            n = n << 1 | p.val
            p = p.next
        return n


if __name__ == '__main__':
    import unittest

    CASES = (
        (create(1, 0, 1), 5),
        (create(0), 0),
    )

    class Test(unittest.TestCase):
        def test(self):
            getDecimalValue = Solution().getDecimalValue
            for head, excepted in CASES:
                actual = getDecimalValue(head)
                self.assertEqual(actual, excepted)

    unittest.main()
