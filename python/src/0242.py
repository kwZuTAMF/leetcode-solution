from collections import Counter


class Solution:

    def isAnagram(self, s: str, t: str) -> bool:
        return sorted(s) == sorted(t)

    # def isAnagram(self, s: str, t: str) -> bool:
    #     return Counter(s) == Counter(t)


if __name__ == '__main__':
    import unittest
    from timeit import timeit

    CASES = (
        ('anagram', 'nagaram', True),
        ('rat', 'car', False),
    )

    class Test(unittest.TestCase):

        def test(self):
            isAnagram = Solution().isAnagram
            for s, t, excepted in CASES:
                actual = isAnagram(s, t)
                self.assertEqual(actual, excepted)

    unittest.main()

    isAnagram = Solution().isAnagram
    for s, t, excepted in CASES:
        print(timeit(lambda: isAnagram(s, t), number=100000))
