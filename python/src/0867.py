class Solution:
    def transpose(self, matrix: list[list[int]]) -> list[list[int]]:
        return list(map(list, zip(*matrix)))


if __name__ == '__main__':
    import unittest

    CASES = (
        ([[1, 2, 3], [4, 5, 6], [7, 8, 9]], [[1, 4, 7], [2, 5, 8], [3, 6, 9]]),
        ([[1, 2, 3], [4, 5, 6]], [[1, 4], [2, 5], [3, 6]]),
    )

    class Test(unittest.TestCase):
        def test(self):
            transpose = Solution().transpose
            for matrix, excepted in CASES:
                actual = transpose(matrix)
                self.assertEqual(actual, excepted)

    unittest.main()
