class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        n, ans = len(nums), []
        if n < 3:
            return ans
        nums.sort()
        if nums[0] > 0 or nums[-1] < 0:
            return ans
        for i in range(n - 2):
            if nums[i] > 0:
                break
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            p, q = i + 1, n - 1
            while p < q:
                s = nums[i] + nums[p] + nums[q]
                if s < 0:
                    p += 1
                elif s > 0:
                    q -= 1
                else:
                    ans.append([nums[i], nums[p], nums[q]])
                    p += 1
                    q -= 1
                    while p < q and nums[p] == nums[p - 1]:
                        p += 1
                    while p < q and nums[q] == nums[q + 1]:
                        q -= 1
        return ans


if __name__ == '__main__':
    import unittest

    CASES = (
        ([-2, -1, -1, -1, 3, 3, 3, 4, 4, 4], [[-2, -1, 3]]),
        ([-1, 0, 1, 2, -1, -4], [[-1, -1, 2], [-1, 0, 1]]),
        ([], []),
        ([0], []),
    )

    class Test(unittest.TestCase):
        def test(self):
            threeSum = Solution().threeSum
            for nums, excepted in CASES:
                actual = threeSum(nums)
                self.assertEqual(actual, excepted)

    unittest.main()

    from timeit import timeit

    threeSum = Solution().threeSum
    for nums, _ in CASES:
        print(timeit(lambda: threeSum(nums), number=100000))
