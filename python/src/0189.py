class Solution:
    def rotate(self, nums: list[int], k: int) -> None:
        '''
        Do not return anything, modify nums in-place instead.
        '''

        n = len(nums)
        k = k % n
        m = n - k
        if k > 0:
            nums[:] = nums[m:] + nums[:m]


if __name__ == '__main__':
    import unittest

    CASES = (
        ([1, 2, 3, 4, 5, 6, 7], 3, [5, 6, 7, 1, 2, 3, 4]),
        ([-1, -100, 3, 99], 2, [3, 99, -1, -100]),
        ([1], 0, [1]),
    )

    class Test(unittest.TestCase):
        def test(self):
            rotate = Solution().rotate
            for nums, k, excepted in CASES:
                rotate(nums, k)
                actual = nums
                self.assertEqual(actual, excepted)

    # unittest.main()

    from timeit import timeit

    rotate = Solution().rotate
    for nums, k, _ in CASES:
        print(timeit(lambda: rotate(nums, k), number=100000))
