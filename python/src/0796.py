class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        return len(s) == len(goal) and goal in s * 2


if __name__ == '__main__':
    import unittest

    CASES = (
        ('abcde', 'cdeab', True),
        ('abcde', 'abced', False),
    )

    class Test(unittest.TestCase):
        def test(self):
            rotateString = Solution().rotateString
            for s, goal, excepted in CASES:
                actual = rotateString(s, goal)
                self.assertEqual(actual, excepted)

    unittest.main()
