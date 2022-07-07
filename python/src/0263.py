class Solution:
    def isUgly(self, n: int) -> bool:
        # if n <= 0:
        #     return False
        # if n <= 10:
        #     return n != 7
        # for i in (5, 3, 2):
        #     while n % i == 0:
        #         n //= i
        # else:
        #     return n == 1

        return n == 1 if n < 2 else (2**31) * (3**19) * (5**13) % n == 0


if __name__ == '__main__':
    import unittest
    from timeit import timeit

    CASES = (
        (0, False),
        (1, True),
        (2, True),
        (3, True),
        (4, True),
        (5, True),
        (6, True),
        (7, False),
        (8, True),
        (9, True),
        (10, True),
        (11, False),
        (12, True),
        (13, False),
        (14, False),
        (15, True),
        (16, True),
        (17, False),
        (18, True),
        (19, False),
    )

    class Test(unittest.TestCase):
        def test(self):
            isUgly = Solution().isUgly
            for n, excepted in CASES:
                actual = isUgly(n)
                self.assertEqual(actual, excepted)

    unittest.main()

    isUgly = Solution().isUgly
    for n, _ in CASES:
        print(timeit(lambda: isUgly(n), number=10000))
