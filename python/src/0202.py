class Solution:
    # def isHappy(self, n: int) -> bool:
    #     fast = slow = n
    #     while True:
    #         slow = self.next(slow)
    #         fast = self.next(fast)
    #         fast = self.next(fast)
    #         if fast == 1:
    #             return True
    #         if slow == fast:
    #             return slow == 1

    def isHappy(self, n: int) -> bool:
        while True:
            if n == 1:
                return True
            if n in {4, 16, 20, 37, 42, 58, 89, 145}:
                return False
            n = self.next(n)

    def next(self, n):
        s = 0
        while n:
            n, m = divmod(n, 10)
            s += m * m
        return s


if __name__ == '__main__':
    import unittest

    CASES = (
        (1, True),
        (2, False),
        (3, False),
        (4, False),
        (5, False),
        (6, False),
        (7, True),
        (8, False),
        (9, False),
        (10, True),
        (11, False),
        (19, True),
        (116, False),
    )

    class Test(unittest.TestCase):
        def test(self):
            isHappy = Solution().isHappy
            for n, excepted in CASES:
                actual = isHappy(n)
                self.assertEqual(actual, excepted)

    unittest.main()

    from timeit import timeit
    isHappy = Solution().isHappy
    for n, excepted in CASES:
        print(timeit(lambda: isHappy(n), number=100000))
