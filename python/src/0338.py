class Solution:
    def countBits(self, n: int) -> list[int]:
        dp = [0]
        for i in range(1, n + 1):
            dp.append(dp[i >> 1] + (i & 1))
        return dp


if __name__ == '__main__':
    import unittest

    CASES = (
        (0, [0]),
        (1, [0, 1]),
        (2, [0, 1, 1]),
        (3, [0, 1, 1, 2]),
        (4, [0, 1, 1, 2, 1]),
        (5, [0, 1, 1, 2, 1, 2]),
        (6, [0, 1, 1, 2, 1, 2, 2]),
        (7, [0, 1, 1, 2, 1, 2, 2, 3]),
        (8, [0, 1, 1, 2, 1, 2, 2, 3, 1]),
        (9, [0, 1, 1, 2, 1, 2, 2, 3, 1, 2]),
        (10, [0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2]),
        (11, [0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3]),
        (12, [0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2]),
        (13, [0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3]),
        (14, [0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3]),
        (15, [0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4]),
    )

    class Test(unittest.TestCase):
        def test(self):
            countBits = Solution().countBits
            for n, excepted in CASES:
                actual = countBits(n)
                self.assertEqual(actual, excepted)

    unittest.main()

    from timeit import timeit

    countBits = Solution().countBits
    for n, _ in CASES:
        print(timeit(lambda: countBits(n), number=100000))
