# yapf: disable
class Solution:
    def intToRoman(self, num: int) -> str:
        return (('', 'M', 'MM', 'MMM')[num // 1000] +
                ('', 'C', 'CC', 'CCC', 'CD', 'D', 'DC', 'DCC', 'DCCC', 'CM')[num % 1000 // 100] +
                ('', 'X', 'XX', 'XXX', 'XL', 'L', 'LX', 'LXX', 'LXXX', 'XC')[num % 100 // 10] +
                ('', 'I', 'II', 'III', 'IV', 'V', 'VI', 'VII', 'VIII', 'IX')[num % 10])


if __name__ == '__main__':
    import unittest

    CASES = (
        (3, 'III'),
        (58, 'LVIII'),
        (1994, 'MCMXCIV'),
    )

    class Test(unittest.TestCase):
        def test(self):
            intToRoman = Solution().intToRoman
            for num, excepted in CASES:
                actual = intToRoman(num)
                self.assertEqual(actual, excepted)

    unittest.main()

    from timeit import timeit

    intToRoman = Solution().intToRoman
    for s, _ in CASES:
        print(timeit(lambda: intToRoman(s), number=1000000))
