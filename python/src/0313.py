from heapq import heappop, heappush


class Solution:
    def nthSuperUglyNumber(self, n: int, primes: list[int]) -> int:
        nums = [1] * n
        heap = [(x, p, 0) for p, x in enumerate(primes)]
        i = 1
        while i < n:
            x, p, u = heappop(heap)
            if x != nums[i - 1]:
                nums[i] = x
                i += 1
            heappush(heap, (nums[u + 1] * primes[p], p, u + 1))
        return nums[n - 1]

    # def nthSuperUglyNumber(self, n: int, primes: list[int]) -> int:
    #     nums, seen = [1], set()
    #     for _ in range(n):
    #         ugly = heappop(nums)
    #         for prime in primes:
    #             next = ugly * prime
    #             if next not in seen:
    #                 seen.add(next)
    #                 heappush(nums, next)
    #     return ugly


if __name__ == '__main__':
    import unittest

    CASES = (
        (12, [2, 7, 13, 19], 32),
        (1, [2, 3, 5], 1),
        (1, [2, 3, 5], 1),
        (2, [2, 3, 5], 2),
        (3, [2, 3, 5], 3),
        (4, [2, 3, 5], 4),
        (5, [2, 3, 5], 5),
        (6, [2, 3, 5], 6),
        (7, [2, 3, 5], 8),
    )

    class Test(unittest.TestCase):
        def test(self):
            nthSuperUglyNumber = Solution().nthSuperUglyNumber
            for n, primes, excepted in CASES:
                actual = nthSuperUglyNumber(n, primes)
                self.assertEqual(actual, excepted)

    unittest.main()

    from timeit import timeit

    nthSuperUglyNumber = Solution().nthSuperUglyNumber
    for n, primes, excepted in CASES:
        print(timeit(lambda: nthSuperUglyNumber(n, primes), number=1000))
