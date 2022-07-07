class Solution:

    def strStr(self, haystack: str, needle: str) -> int:
        n = len(haystack)
        m = len(needle)
        if m == 0:
            return 0
        next = bytearray(m)
        j = 0
        for i in range(1, m):
            while j > 0 and needle[i] != needle[j]:
                j = next[j - 1]
            if needle[i] == needle[j]:
                j += 1
            next[i] = j
        j = 0
        for i in range(n):
            while j > 0 and haystack[i] != needle[j]:
                j = needle[j - 1]
            if haystack[i] == needle[j]:
                j += 1
            if j == m:
                return i - m + 1
        return -1


if __name__ == '__main__':
    import unittest
    from timeit import timeit

    CASES = (
        ('hello', 'll', 2),
        ('aaaaa', 'bba', -1),
    )

    class Test(unittest.TestCase):

        def test(self):
            strStr = Solution().strStr
            for haystack, needle, excepted in CASES:
                actual = strStr(haystack, needle)
                self.assertEqual(actual, excepted)

    unittest.main()

    strStr = Solution().strStr
    for haystack, needle, excepted in CASES:
        print(timeit(lambda: strStr(haystack, needle), number=100000))
