from collections import Counter


class Solution:

    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        return len(ransomNote) <= len(magazine) and not Counter(ransomNote) - Counter(magazine)


if __name__ == '__main__':
    import unittest
    from timeit import timeit

    CASES = (
        ('a', 'b', False),
        ('aa', 'ab', False),
        ('aa', 'aab', True),
        ('aab', 'aab', True),
    )

    class Test(unittest.TestCase):

        def test(self):
            canConstruct = Solution().canConstruct
            for ransomNote, magazine, excepted in CASES:
                actual = canConstruct(ransomNote, magazine)
                self.assertEqual(actual, excepted)

    unittest.main()

    canConstruct = Solution().canConstruct
    for ransomNote, magazine, excepted in CASES:
        print(timeit(lambda: canConstruct(ransomNote, magazine), number=100000))
