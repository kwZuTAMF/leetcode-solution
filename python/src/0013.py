# yapf: disable
class Solution:
    def romanToInt(self, s: str) -> int:
        n = 0
        p = ''
        for c in s:
            match c:
                case 'M': n += 800 if p == 'C' else 1000
                case 'D': n += 300 if p == 'C' else 500
                case 'C': n += 80 if p == 'X' else 100
                case 'L': n += 30 if p == 'X' else 50
                case 'X': n += 8 if p == 'I' else 10
                case 'V': n += 3 if p == 'I' else 5
                case 'I': n += 1
            p = c
        return n

    # def romanToInt(self, s: str) -> int:
    #     n = 0
    #     for c in s[::-1]:
    #         match c:
    #             case 'I': n += -1 if n >= 5 else 1
    #             case 'V': n += 5
    #             case 'X': n += -10 if n >= 50 else 10
    #             case 'L': n += 50
    #             case 'C': n += -100 if n >= 500 else 100
    #             case 'D': n += 500
    #             case 'M': n += 1000
    #     return n


if __name__ == '__main__':
    import unittest

    CASES = (
        ('III', 3),
        ('LVIII', 58),
        ('MCMXCIV', 1994),
    )

    class Test(unittest.TestCase):
        def test(self):
            romanToInt = Solution().romanToInt
            for s, excepted in CASES:
                actual = romanToInt(s)
                self.assertEqual(actual, excepted)

    unittest.main()

    from timeit import timeit

    romanToInt = Solution().romanToInt
    for s, _ in CASES:
        print(timeit(lambda: romanToInt, number=1000000))
