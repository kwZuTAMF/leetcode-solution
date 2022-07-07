class Solution:

    def largestSumAfterKNegations(self, nums: list[int], k: int) -> int:
        nums.sort(key=abs)
        for i in range(len(nums) - 1, -1, -1):
            if not k:
                break
            if nums[i] < 0:
                nums[i] *= -1
                k -= 1
        if k & 1:
            nums[0] *= -1
        return sum(nums)


if __name__ == '__main__':
    import unittest
    from timeit import timeit

    CASES = (
        ([4, 2, 3], 1, 5),
        ([3, -1, 0, 2], 3, 6),
        ([2, -3, -1, 5, -4], 2, 13),
    )

    class Test(unittest.TestCase):

        def test(self):
            largestSumAfterKNegations = Solution().largestSumAfterKNegations
            for nums, k, excepted in CASES:
                actual = largestSumAfterKNegations(nums, k)
                self.assertEqual(actual, excepted)

    unittest.main()

    largestSumAfterKNegations = Solution().largestSumAfterKNegations
    for nums, k, _ in CASES:
        print(timeit(lambda: largestSumAfterKNegations(nums, k), number=100000))
