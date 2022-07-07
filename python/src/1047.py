# [1047. Remove All Adjacent Duplicates In String (Easy)](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/)
# @topic String
# @topic Stack
#
# Constraints:
# 1 <= s.length <= 10^5
# s consists of lowercase English letters.

from collections import deque


class Solution:

    def removeDuplicates(self, s: str) -> str:
        stk = deque()
        for c in s:
            if stk and stk[-1] == c:
                stk.pop()
            else:
                stk.append(c)
        return ''.join(stk)


if __name__ == '__main__':
    import unittest
    from timeit import timeit

    CASES = (
        ('abbaca', 'ca'),
        ('azxxzy', 'ay'),
    )

    class Test(unittest.TestCase):

        def test(self):
            removeDuplicates = Solution().removeDuplicates
            for s, excepted in CASES:
                actual = removeDuplicates(s)
                self.assertEqual(actual, excepted)

    unittest.main()

    removeDuplicates = Solution().removeDuplicates
    for s, excepted in CASES:
        print(timeit(lambda: removeDuplicates(s), number=100000))
