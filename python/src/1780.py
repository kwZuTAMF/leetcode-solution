class Solution:
    def checkPowersOfThree(self, n: int) -> bool:
        while n:
            n, m = divmod(n, 3)
            if m == 2:
                return False
        return True


if __name__ == '__main__':
    import unittest
    from timeit import timeit

    CASES = (
        (12, True),
        (91, True),
        (21, False),
    )

    class Test(unittest.TestCase):
        def test(self):
            checkPowersOfThree = Solution().checkPowersOfThree
            for n, excepted in CASES:
                actual = checkPowersOfThree(n)
                self.assertEqual(actual, excepted)

    unittest.main()

    checkPowersOfThree = Solution().checkPowersOfThree
    for n, _ in CASES:
        print(timeit(lambda: checkPowersOfThree(n), number=1000000))
