class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x <= 9:
            return x >= 0
        if x % 10 == 0:
            return False
        p, q = 0, x
        while q > p:
            q, r = divmod(q, 10)
            p = p * 10 + r
        return p == q or p // 10 == q


if __name__ == '__main__':
    import unittest
    from timeit import timeit

    CASES = (
        (-1, False),
        (-10, False),
        (-11, False),
        (-111, False),
        (0, True),
        (1, True),
        (2, True),
        (3, True),
        (4, True),
        (5, True),
        (6, True),
        (7, True),
        (8, True),
        (9, True),
        (10, False),
        (121, True),
        (1001, True),
        (10201, True),
    )

    class Test(unittest.TestCase):
        def test(self):
            isPalindrome = Solution().isPalindrome
            for x, excepted in CASES:
                actual = isPalindrome(x)
                self.assertEqual(actual, excepted)

    unittest.main()

    isPalindrome = Solution().isPalindrome
    for x, _ in CASES:
        print(timeit(lambda: isPalindrome(x), number=10000))
