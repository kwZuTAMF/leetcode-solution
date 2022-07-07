class Solution:
    def countPrimes(self, n: int) -> int:
        if n < 3:
            return 0
        sieve = bytearray(n)
        for i in range(3, int(n**0.5) + 1, 2):
            if not sieve[i]:
                sieve[i * i::i * 2] = [1] * ((n - i * i - 1) // (i * 2) + 1)
        return (n // 2) - sum(sieve)


if __name__ == '__main__':
    import unittest

    CASES = (
        (0, 0),
        (1, 0),
        (2, 0),
        (3, 1),
        (4, 2),
        (5, 2),
        (6, 3),
        (7, 3),
        (8, 4),
        (9, 4),
        (10, 4),
        (11, 4),
        (12, 5),
        (13, 5),
        (14, 6),
        (15, 6),
        (10000, 1229),
        (499979, 41537),
        (999983, 78497),
        (1500000, 114155),
    )

    class Test(unittest.TestCase):

        def test(self):
            countPrimes = Solution().countPrimes
            for n, excepted in CASES:
                actual = countPrimes(n)
                self.assertEqual(actual, excepted)

    unittest.main()
