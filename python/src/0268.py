class Solution:
    def missingNumber(self, nums: list[int]) -> int:
        n = len(nums)
        return n * (n + 1) // 2 - sum(nums)

    # def missingNumber(self, nums: list[int]) -> int:
    #     n = len(nums)
    #     match n % 4:
    #         case 0:
    #             x = n
    #         case 1:
    #             x = 1
    #         case 2:
    #             x = n + 1
    #         case _:
    #             x = 0
    #     for i in nums:
    #         x ^= i
    #     else:
    #         return x

    # def missingNumber(self, nums: list[int]) -> int:
    #     n = len(nums)
    #     s = set(nums)
    #     for i in range(n):
    #         if i not in s:
    #             return i
    #     else:
    #         return n

    # def missingNumber(self, nums: list[int]) -> int:
    #     for i, x in enumerate(sorted(nums)):
    #         if i != x:
    #             return i
    #     else:
    #         return len(nums)


if __name__ == '__main__':
    import unittest

    CASES = (
        ([3, 0, 1], 2),
        ([0, 1], 2),
        ([9, 6, 4, 2, 3, 5, 7, 0, 1], 8),
        ([1], 0),
    )

    class Test(unittest.TestCase):
        def test(self):
            missingNumber = Solution().missingNumber
            for nums, excepted in CASES:
                actual = missingNumber(nums)
                self.assertEqual(actual, excepted)

    # unittest.main()

    from timeit import timeit

    missingNumber = Solution().missingNumber
    for nums, _ in CASES:
        print(timeit(lambda: missingNumber(nums), number=100000))
