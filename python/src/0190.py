class Solution:
    # def reverseBits(self, n: int) -> int:
    #     rev = 0
    #     for i in range(32):
    #         if not n:
    #             break
    #         rev |= (n & 1) << (31 - i)
    #         n >>= 1
    #     return rev

    def reverseBits(self, n: int) -> int:
        n = n << 16 | n >> 16
        n = (n & 0x00FF00FF) << 8 | (n >> 8) & 0x00FF00FF
        n = (n & 0x0F0F0F0F) << 4 | (n >> 4) & 0x0F0F0F0F
        n = (n & 0x33333333) << 2 | (n >> 2) & 0x33333333
        n = (n & 0x55555555) << 1 | (n >> 1) & 0x55555555
        return n


if __name__ == '__main__':
    import unittest
    from timeit import timeit

    CASES = (
        (0b00000010100101000001111010011100, 0b00111001011110000010100101000000),
        (0b11111111111111111111111111111101, 0b10111111111111111111111111111111),
    )

    class Test(unittest.TestCase):
        def test(self):
            reverseBits = Solution().reverseBits
            for n, excepted in CASES:
                actual = reverseBits(n)
                self.assertEqual(actual, excepted)

    unittest.main()

    reverseBits = Solution().reverseBits
    for n, _ in CASES:
        print(timeit(lambda: reverseBits(n), number=1000000))
