class Solution:

    def intersection(self, nums1: list[int], nums2: list[int]) -> list[int]:
        return list(set(nums1) & set(nums2))


if __name__ == '__main__':
    import unittest
    from timeit import timeit

    CASES = (
        ([1, 2, 2, 1], [2, 2], [2]),
        ([4, 9, 5], [9, 4, 9, 8, 4], [9, 4]),
    )

    class Test(unittest.TestCase):

        def test(self):
            intersection = Solution().intersection
            for nums1, nums2, excepted in CASES:
                actual = intersection(nums1, nums2)
                self.assertEqual(actual, excepted)

    unittest.main()

    intersection = Solution().intersection
    for nums1, nums2, _ in CASES:
        print(timeit(lambda: intersection(nums1, nums2), number=100000))
