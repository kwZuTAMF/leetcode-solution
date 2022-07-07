# [20. Valid Parentheses (Easy)](https://leetcode.com/problems/valid-parentheses/)
# @topic String
# @topic Stack
#
# Constraints:
# 1 <= s.length <= 10^4
# s consists of parentheses only '()[]{}'.

from collections import deque


class Solution:

    def isValid(self, s: str) -> bool:
        if len(s) & 1:
            return False
        stk = deque()
        for c in s:
            match c:
                case '(': stk.append(')')
                case '[': stk.append(']')
                case '{': stk.append('}')
                case _ if stk and stk.pop() != c:
                    return False
        return not stk


if __name__ == '__main__':
    import unittest
    from timeit import timeit

    CASES = (
        ('()', True),
        ('()[]{}', True),
        ('(]', False),
    )

    class Test(unittest.TestCase):

        def test(self):
            isValid = Solution().isValid
            for s, excepted in CASES:
                actual = isValid(s)
                self.assertEqual(actual, excepted)

    unittest.main()

    isValid = Solution().isValid
    for s, excepted in CASES:
        print(timeit(lambda: isValid(s), number=100000))
