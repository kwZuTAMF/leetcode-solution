from math import inf


class Solution:

    def minSubArrayLen(self, target: int, nums: list[int]) -> int:
        n, m = len(nums), inf
        s = i = j = 0
        while j < n:
            s += nums[i]
            while s >= target:
                m = min(m, j - i + 1)
                s -= nums[i]
                i += 1
            j += 1
        return m if m != inf else 0


if __name__ == '__main__':
    import unittest
    from timeit import timeit

    CASES = (
        (7, [2, 3, 1, 2, 4, 3], 2),
        (4, [1, 4, 4], 1),
        (11, [1, 1, 1, 1, 1, 1, 1, 1], 0),
    )

    class Test(unittest.TestCase):

        def test(self):
            minSubArrayLen = Solution().minSubArrayLen
            for target, nums, excepted in CASES:
                actual = minSubArrayLen(target, nums)
                self.assertEqual(actual, excepted)

    # unittest.main()

    minSubArrayLen = Solution().minSubArrayLen
    for target, nums, excepted in CASES:
        print(timeit(lambda: minSubArrayLen(target, nums), number=100000))
