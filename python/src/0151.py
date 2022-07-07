class Solution:

    def reverseWords(self, s: str) -> str:
        words = [*s][::-1]
        fast, slow, size = 0, 0, len(s)
        while fast < size:
            if words[fast] != ' ':
                if slow > 0:
                    words[slow] = ' '
                    slow += 1
                k = fast
                while k < size and words[k] != ' ':
                    words[slow] = words[k]
                    slow += 1
                    k += 1
                start = slow - (k - fast)
                words[start:slow] = words[start:slow][::-1]
                fast = k
            fast += 1
        return ''.join(words[:slow])


if __name__ == '__main__':
    import unittest
    from timeit import timeit

    CASES = (
        ("the sky is blue", "blue is sky the"),
        ("  hello world  ", "world hello"),
        ("a good   example", "example good a"),
    )

    class Test(unittest.TestCase):

        def test(self):
            reverseWords = Solution().reverseWords
            for s, excepted in CASES:
                actual = reverseWords(s)
                self.assertEqual(actual, excepted)

    unittest.main()

    reverseWords = Solution().reverseWords
    for s, _ in CASES:
        print(timeit(lambda: reverseWords(s), number=100000))
