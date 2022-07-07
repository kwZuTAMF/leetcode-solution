# [150. Evaluate Reverse Polish Notation (Medium)](https://leetcode.com/problems/evaluate-reverse-polish-notation/)
# @topic Array
# @topic Math
# @topic Stack
#
# Constraints:
# 1 <= tokens.length <= 10^4
# tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].

from collections import deque


class Solution:

    def evalRPN(self, tokens: list[str]) -> int:
        stk = deque()
        for token in tokens:
            if token in {'+', '-', '*', '/'}:
                y, x = stk.pop(), stk.pop()
                match token:
                    case '+': stk.append(x + y)
                    case '-': stk.append(x - y)
                    case '*': stk.append(x * y)
                    case '/': stk.append(int(x / y))
            else:
                stk.append(int(token))
        return stk.pop()


if __name__ == '__main__':
    import unittest
    from timeit import timeit

    CASES = (
        (["2", "1", "+", "3", "*"], 9),
        (["4", "13", "5", "/", "+"], 6),
        (["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"], 22),
    )

    class Test(unittest.TestCase):

        def test(self):
            evalRPN = Solution().evalRPN
            for tokens, excepted in CASES:
                actual = evalRPN(tokens)
                self.assertEqual(actual, excepted)

    unittest.main()

    evalRPN = Solution().evalRPN
    for tokens, excepted in CASES:
        print(timeit(lambda: evalRPN(tokens), number=100000))
