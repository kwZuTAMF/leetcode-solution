class Solution:

    def sortedSquares(self, nums: list[int]) -> list[int]:
        n = len(nums)
        i = 0
        j = n - 1
        k = n - 1
        squares = [0] * n
        while i <= j:
            if -nums[i] > nums[j]:
                squares[k] = nums[i] * nums[i]
                i += 1
            else:
                squares[k] = nums[j] * nums[j]
                j -= 1
            k -= 1
        return squares

    # def sortedSquares(self, nums: list[int]) -> list[int]:
    #     n = len(nums)
    #     m = 0
    #     while m < n and nums[m] < 0:
    #         m += 1
    #     i = m - 1
    #     j = m
    #     squares = []
    #     while i >= 0 and j < n:
    #         if -nums[i] < nums[j]:
    #             squares.append(nums[i] * nums[i])
    #             i -= 1
    #         else:
    #             squares.append(nums[j] * nums[j])
    #             j += 1
    #     while i >= 0:
    #         squares.append(nums[i] * nums[i])
    #         i -= 1
    #     while j < n:
    #         squares.append(nums[j] * nums[j])
    #         j += 1
    #     return squares


if __name__ == '__main__':
    import unittest
    from timeit import timeit

    CASES = (
        ([-4, -1, 0, 3, 10], [0, 1, 9, 16, 100]),
        ([-7, -3, 2, 3, 11], [4, 9, 9, 49, 121]),
    )

    class Test(unittest.TestCase):

        def test(self):
            sortedSquares = Solution().sortedSquares
            for nums, excepted in CASES:
                actual = sortedSquares(nums)
                self.assertEqual(actual, excepted)

    # unittest.main()

    sortedSquares = Solution().sortedSquares
    for nums, excepted in CASES:
        print(timeit(lambda: sortedSquares(nums), number=100000))
