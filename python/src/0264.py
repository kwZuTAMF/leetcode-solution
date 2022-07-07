class Solution:
    def nthUglyNumber(self, n: int) -> int:
        dp = [1] * n
        i2, i3, i5 = 0, 0, 0
        for i in range(1, n):
            n2, n3, n5 = dp[i2] * 2, dp[i3] * 3, dp[i5] * 5
            next = min(n2, n3, n5)
            if next == n2:
                i2 += 1
            if next == n3:
                i3 += 1
            if next == n5:
                i5 += 1
            dp[i] = next
        return dp[n - 1]


if __name__ == '__main__':
    import unittest

    CASES = (
        (1, 1),
        (10, 12),
    )

    class Test(unittest.TestCase):
        def test(self):
            nthUglyNumber = Solution().nthUglyNumber
            for n, excepted in CASES:
                actual = nthUglyNumber(n)
                self.assertEqual(actual, excepted)

    unittest.main()
