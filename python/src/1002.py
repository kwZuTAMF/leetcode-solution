from collections import Counter
from functools import reduce
from operator import and_


class Solution:

    def commonChars(self, words: list[str]) -> list[str]:
        return list(reduce(and_, map(Counter, words)).elements())

    # def commonChars(self, words: list[str]) -> list[str]:
    #     head, *tail = words
    #     freq = Counter(head)
    #     for item in tail:
    #         freq &= Counter(item)
    #     return list(freq.elements())


if __name__ == '__main__':
    import unittest
    from timeit import timeit

    CASES = (
        (["bella", "label", "roller"], ["e", "l", "l"]),
        (["cool", "lock", "cook"], ["c", "o"]),
    )

    class Test(unittest.TestCase):

        def test(self):
            commonChars = Solution().commonChars
            for words, excepted in CASES:
                actual = commonChars(words)
                self.assertEqual(actual, excepted)

    unittest.main()

    commonChars = Solution().commonChars
    for words, _ in CASES:
        print(timeit(lambda: commonChars(words), number=100000))
