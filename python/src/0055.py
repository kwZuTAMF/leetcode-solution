class Solution:

    def canJump(self, nums: list[int]) -> bool:
        k = nums[0]
        for i in range(1, len(nums)):
            if i <= k:
                k = max(k, i + nums[i])
            else:
                return False
        return True

    # def canJump(self, nums: list[int]) -> bool:
    #     for i in range(len(nums) - 2, -1, -1):
    #         if nums[i] == 0:
    #             for j in range(i - 1, -1, -1):
    #                 if nums[j] > i - j:
    #                     break
    #             else:
    #                 return False
    #     return True


if __name__ == '__main__':
    import unittest
    from timeit import timeit

    CASES = (
        ([2, 3, 1, 1, 4], True),
        ([3, 2, 1, 0, 4], False),
        ([0, 1], False),
        ([0, 0, 0, 1], False),
        ([0, 0, 0, 1, 0], False),
    )

    class Test(unittest.TestCase):

        def test(self):
            canJump = Solution().canJump
            for nums, excepted in CASES:
                actual = canJump(nums)
                self.assertEqual(actual, excepted)

    unittest.main()

    canJump = Solution().canJump
    for nums, _ in CASES:
        print(timeit(lambda: canJump(nums), number=100000))
