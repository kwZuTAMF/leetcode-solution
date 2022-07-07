class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        return n > 0 and 3**19 % n == 0


if __name__ == '__main__':
    import unittest
    from timeit import timeit

    CASES = (
        (0, False),
        (1, True),
        (2, False),
        (3, True),
        (4, False),
        (5, False),
        (6, False),
        (7, False),
        (8, False),
        (9, True),
        (10, False),
        (27, True),
        (45, False),
        (81, True),
        (243, True),
        (729, True),
        (2187, True),
        (6561, True),
        (19683, True),
    )

    class Test(unittest.TestCase):
        def test(self):
            isPowerOfThree = Solution().isPowerOfThree
            for n, excepted in CASES:
                actual = isPowerOfThree(n)
                self.assertEqual(actual, excepted)

    unittest.main()

    isPowerOfThree = Solution().isPowerOfThree
    for n, _ in CASES:
        print(timeit(lambda: isPowerOfThree(n), number=10000))
