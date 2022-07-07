# yapf: disable
class Solution:
    def fizzBuzz(self, n: int) -> list[str]:
        return [(i % 5 == 0 and 'FizzBuzz' or 'Fizz') if i % 3 == 0 else
                (i % 5 == 0 and 'Buzz' or str(i)) for i in range(1, n + 1)]


if __name__ == '__main__':
    import unittest

    CASES = (
        (3, ['1', '2', 'Fizz']),
        (5, ['1', '2', 'Fizz', '4', 'Buzz']),
        (15, ['1', '2', 'Fizz', '4', 'Buzz', 'Fizz', '7', '8', 'Fizz', 'Buzz', '11', 'Fizz', '13', '14', 'FizzBuzz']),
    )

    class Test(unittest.TestCase):

        def test(self):
            fizzBuzz = Solution().fizzBuzz
            for n, excepted in CASES:
                actual = fizzBuzz(n)
                self.assertEqual(actual, excepted)

    unittest.main()
