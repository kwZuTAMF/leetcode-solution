class Solution:
    def moveZeroes(self, nums: list[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """

        j = 0
        for i in range(len(nums)):
            if i != j and nums[i]:
                nums[i], nums[j] = nums[j], nums[i]
                j += 1


if __name__ == '__main__':
    import unittest
    from timeit import timeit

    CASES = (
        ([0, 1, 0, 3, 12], [1, 3, 12, 0, 0]),
        ([0], [0]),
        ([1, 2, 3, 4, 5, 6, 7, 8, 9, 0], [1, 2, 3, 4, 5, 6, 7, 8, 9, 0]),
    )

    class Test(unittest.TestCase):
        def test(self):
            moveZeroes = Solution().moveZeroes
            for nums, excepted in CASES:
                moveZeroes(nums)
                actual = nums
                self.assertEqual(actual, excepted)

    # unittest.main()

    moveZeroes = Solution().moveZeroes
    for nums, _ in CASES:
        print(timeit(lambda: moveZeroes(nums), number=10000))
