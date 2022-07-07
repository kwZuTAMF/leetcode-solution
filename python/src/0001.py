class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        d = {}
        for i, x in enumerate(nums):
            if target - x in d:
                return [d[target - x], i]
            d[x] = i


if __name__ == '__main__':
    import unittest
    from timeit import timeit

    CASES = (
        ([2, 7, 11, 15], 9, [0, 1]),
        ([3, 2, 4], 6, [1, 2]),
        ([3, 3], 6, [0, 1]),
    )

    class Test(unittest.TestCase):
        def test(self):
            twoSum = Solution().twoSum
            for nums, target, excepted in CASES:
                actual = twoSum(nums, target)
                self.assertEqual(actual, excepted)

    unittest.main()

    twoSum = Solution().twoSum
    for nums, target, excepted in CASES:
        print(timeit(lambda: twoSum(nums, target), number=100000))
