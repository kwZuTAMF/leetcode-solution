from collections import Counter


class Solution:

    def topKFrequent(self, nums: list[int], k: int) -> list[int]:
        return [x for _, x in sorted(((v, k) for k, v in Counter(nums).items()), reverse=True)[:k]]


if __name__ == '__main__':
    import unittest
    from timeit import timeit

    CASES = (
        ([1, 1, 1, 2, 2, 3], 2, [1, 2]),
        ([1], 1, [1]),
    )

    class Test(unittest.TestCase):

        def test(self):
            topKFrequent = Solution().topKFrequent
            for nums, k, excepted in CASES:
                actual = topKFrequent(nums, k)
                self.assertEqual(actual, excepted)

    # unittest.main()

    topKFrequent = Solution().topKFrequent
    for nums, k, excepted in CASES:
        print(timeit(lambda: topKFrequent(nums, k), number=100000))
