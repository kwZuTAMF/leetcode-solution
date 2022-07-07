class Solution:
    def numSquares(self, n: int) -> int:
        if (n**0.5).is_integer():
            return 1
        while n % 4 == 0:
            n /= 4
        if n % 8 == 7:
            return 4
        for i in range(1, int(n**0.5) + 1):
            if ((n - i * i) ** 0.5).is_integer():
                return 2
        return 3


if __name__ == '__main__':
    import unittest

    CASES = (
        (1, 1),
        (3, 3),
        (5, 2),
        (7, 4),
        (12, 3),
        (13, 2),
        (16, 1),
        (42, 3),
        (63, 4),
    )

    class Test(unittest.TestCase):
        def test(self):
            numSquares = Solution().numSquares
            for n, excepted in CASES:
                actual = numSquares(n)
                self.assertEqual(actual, excepted)

    unittest.main()

    from timeit import timeit

    numSquares = Solution().numSquares
    for n, _ in CASES:
        print(timeit(lambda: numSquares(n), number=100000))
