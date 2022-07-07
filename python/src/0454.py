from collections import Counter


class Solution:
    # def fourSumCount(self, nums1: list[int], nums2: list[int], nums3: list[int], nums4: list[int]) -> int:
    #     count = Counter(x + y for x in nums1 for y in nums2)
    #     return sum(count.get(-x - y, 0) for x in nums3 for y in nums4)

    def fourSumCount(self, nums1: list[int], nums2: list[int], nums3: list[int], nums4: list[int]) -> int:
        count, counter = 0, {}
        for x in nums1:
            for y in nums2:
                s = x + y
                if s in counter:
                    counter[s] += 1
                else:
                    counter[s] = 1
        for x in nums3:
            for y in nums4:
                s = -x - y
                if s in counter:
                    count += counter[s]
        return count


if __name__ == '__main__':
    import unittest

    CASES = (
        ([1, 2], [-2, -1], [-1, 2], [0, 2], 2),
        ([0], [0], [0], [0], 1),
    )

    class Test(unittest.TestCase):
        def test(self):
            fourSumCount = Solution().fourSumCount
            for nums1, nums2, nums3, nums4, excepted in CASES:
                actual = fourSumCount(nums1, nums2, nums3, nums4)
                self.assertEqual(actual, excepted)

    # unittest.main()

    from timeit import timeit

    fourSumCount = Solution().fourSumCount
    for nums1, nums2, nums3, nums4, excepted in CASES:
        print(timeit(lambda: fourSumCount(nums1, nums2, nums3, nums4), number=100000))
