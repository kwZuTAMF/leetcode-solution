# [107. Binary Tree Level Order Traversal II (Medium)](https://leetcode.com/problems/binary-tree-level-order-traversal-ii/)
# @topic Tree
# @topic Breadth-First Search
# @topic Binary Tree
#
# Constraints:
# The number of nodes in the tree is in the range [0, 2000].
# -1000 <= Node.val <= 1000

from collections import deque
from typing import Optional

from structs.BinaryTree import create, TreeNode


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def levelOrderBottom(self, root: Optional[TreeNode]) -> list[list[int]]:
        if root:
            res = []
            q = deque([root])
            while q:
                res.append([])
                for _ in range(len(q)):
                    cur = q.popleft()
                    res[-1].append(cur.val)
                    cur.left and q.append(cur.left)
                    cur.right and q.append(cur.right)
            return res[::-1]
        else:
            return []


if __name__ == '__main__':
    import unittest
    from timeit import timeit

    CASES = (
        (create(TreeNode, 3, 9, 20, None, None, 15, 7), [[15, 7], [9, 20], [3]]),
        (create(TreeNode, 1), [[1]]),
        (None, []),
    )

    class Test(unittest.TestCase):

        def test(self):
            levelOrderBottom = Solution().levelOrderBottom
            for root, excepted in CASES:
                actual = levelOrderBottom(root)
                self.assertEqual(actual, excepted)

    # unittest.main()

    levelOrderBottom = Solution().levelOrderBottom
    for root, excepted in CASES:
        print(timeit(lambda: levelOrderBottom(root), number=100000))
