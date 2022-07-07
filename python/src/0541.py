class Solution:

    def reverseStr(self, s: str, k: int) -> str:
        s = list(s)
        for i in range(0, len(s), k << 1):
            s[i:i + k] = s[i:i + k][::-1]
        return ''.join(s)


if __name__ == '__main__':
    import unittest
    from timeit import timeit

    CASES = (
        ('abcdefg', 2, 'bacdfeg'),
        ('abcd', 2, 'bacd'),
    )

    class Test(unittest.TestCase):

        def test(self):
            reverseStr = Solution().reverseStr
            for s, k, excepted in CASES:
                actual = reverseStr(s, k)
                self.assertEqual(actual, excepted)

    # unittest.main()

    reverseStr = Solution().reverseStr
    for s, k, excepted in CASES:
        print(timeit(lambda: reverseStr(s, k), number=100000))
