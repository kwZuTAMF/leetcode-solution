class Solution:
    # yapf: disable
    def __init__(self) -> None:
        self.table = (
            0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4,
            1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
            1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
            2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
            1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
            2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
            2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
            3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
            1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
            2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
            2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
            3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
            2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
            3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
            3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
            4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8,
        )

    def hammingWeight(self, n: int) -> int:
        return (self.table[(n >> 0x00) & 0xff] +
                self.table[(n >> 0x08) & 0xff] +
                self.table[(n >> 0x10) & 0xff] +
                self.table[(n >> 0x18) & 0xff])
    # yapf: enable

    # def hammingWeight(self, n: int) -> int:
    #     n -= (n >> 1) & 0x55555555
    #     n = (n & 0x33333333) + ((n >> 2) & 0x33333333)
    #     n = (n + (n >> 4)) & 0x0F0F0F0F
    #     n += n >> 8
    #     n += n >> 16
    #     return n & 0x3F


if __name__ == '__main__':
    import unittest

    CASES = (
        (0b00000000000000000000000000001011, 3),
        (0b00000000000000000000000010000000, 1),
        (0b11111111111111111111111111111101, 31),
    )

    class Test(unittest.TestCase):
        def test(self):
            hammingWeight = Solution().hammingWeight
            for n, excepted in CASES:
                actual = hammingWeight(n)
                self.assertEqual(actual, excepted)

    # unittest.main()

    from timeit import timeit

    hammingWeight = Solution().hammingWeight
    for n, excepted in CASES:
        print(timeit(lambda: hammingWeight(n), number=1000000))
