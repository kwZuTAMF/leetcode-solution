from collections import deque


class Solution:
    def openLock(self, deadends: list[str], target: str) -> int:
        if (init := (0, 0, 0, 0)) == (stop := tuple(map(int, target))):
            return 0
        if init in (seen := {tuple(map(int, x)) for x in deadends}):
            return -1
        seen.add(init)
        q = deque([(init, 0)])
        while q:
            node, step = q.popleft()
            if node == stop:
                return step
            for node in self.get_neighbors(node):
                if node not in seen:
                    seen.add(node)
                    q.append((node, step + 1))
        return -1

    def get_neighbors(self, node):
        a, b, c, d = node
        return (
            ((a - 1) % 10, b, c, d),
            ((a + 1) % 10, b, c, d),
            (a, (b - 1) % 10, c, d),
            (a, (b + 1) % 10, c, d),
            (a, b, (c - 1) % 10, d),
            (a, b, (c + 1) % 10, d),
            (a, b, c, (d - 1) % 10),
            (a, b, c, (d + 1) % 10),
        )


if __name__ == '__main__':
    import unittest
    from timeit import timeit

    CASES = (
        (['0201', '0101', '0102', '1212', '2002'], '0202', 6),
        (['8888'], '0009', 1),
        (['8887', '8889', '8878', '8898', '8788', '8988', '7888', '9888'], '8888', -1),
        (['8888'], '0000', 0),
        (['0000'], '8888', -1),
        (['9000'], '8888', 8),
        # Invalid Testcase: Found target in deadends
        # (['0000'], '0000', -1),
    )

    class Test(unittest.TestCase):
        def test(self):
            openLock = Solution().openLock
            for deadends, target, excepted in CASES:
                actual = openLock(deadends, target)
                self.assertEqual(actual, excepted)

    unittest.main()

    openLock = Solution().openLock
    for deadends, target, _ in CASES:
        print(timeit(lambda: openLock(deadends, target), number=100))
