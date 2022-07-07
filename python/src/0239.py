# [239. Sliding Window Maximum (Hard)](https://leetcode.com/problems/sliding-window-maximum/)
# @topic Array
# @topic Queue
# @topic Sliding Window
# @topic Heap (Priority Queue)
# @topic Monotonic Queue
#
# Constraints:
# 1 <= nums.length <= 10^5
# -10^4 <= nums[i] <= 10^4
# 1 <= k <= nums.length

from itertools import accumulate


class Solution:

    def maxSlidingWindow(self, nums: list[int], k: int) -> list[int]:
        return list(accumulate(nums[k:], max, initial=max(nums[:k]))) if len(nums) > 1 else nums


if __name__ == '__main__':
    import unittest
    from timeit import timeit

    CASES = (
        ([1, 3, -1, -3, 5, 3, 6, 7], 3, [3, 3, 5, 5, 6, 7]),
        ([1], 1, [1]),
    )

    class Test(unittest.TestCase):

        def test(self):
            maxSlidingWindow = Solution().maxSlidingWindow
            for nums, k, excepted in CASES:
                actual = maxSlidingWindow(nums, k)
                self.assertEqual(actual, excepted)

    unittest.main()

    maxSlidingWindow = Solution().maxSlidingWindow
    for nums, k, excepted in CASES:
        print(timeit(lambda: maxSlidingWindow(nums, k), number=100000))
