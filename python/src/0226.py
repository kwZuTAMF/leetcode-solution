# [226. Invert Binary Tree (Easy)](https://leetcode.com/problems/invert-binary-tree/)
# @topic Tree
# @topic Depth-First Search
# @topic Breadth-First Search
# @topic Binary Tree
#
# Constraints:
# The number of nodes in the tree is in the range [0, 100].
# -100 <= Node.val <= 100

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

    # pre-order
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if root:
            stk = deque()
            cur = root
            while cur or stk:
                while cur:
                    cur.left, cur.right = cur.right, cur.left
                    stk.append(cur)
                    cur = cur.left
                cur = stk.pop().right
        return root

    # in-order
    # def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
    #     if root:
    #         stk = deque()
    #         cur = root
    #         while cur or stk:
    #             while cur:
    #                 stk.append(cur)
    #                 cur = cur.left
    #             cur = stk.pop()
    #             cur.left, cur.right = cur.right, cur.left
    #             cur = cur.left
    #     return root

    # post-order
    # def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
    #     if root:
    #         stk = deque()
    #         cur = root
    #         pre = None
    #         while cur or stk:
    #             while cur:
    #                 stk.append(cur)
    #                 cur = cur.left
    #             cur = stk[-1]
    #             if cur.right and cur.right != pre:
    #                 cur = cur.right
    #             else:
    #                 stk.pop()
    #                 cur.left, cur.right = cur.right, cur.left
    #                 pre = cur
    #                 cur = None
    #     return root

    # bfs
    # def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
    #     if root:
    #         q = deque([root])
    #         while q:
    #             for _ in range(len(q)):
    #                 node = q.popleft()
    #                 node.left, node.right = node.right, node.left
    #                 node.left and q.append(node.left)
    #                 node.right and q.append(node.right)
    #     return root


if __name__ == '__main__':
    import unittest
    from timeit import timeit

    CASES = (
        (create(TreeNode, 4, 2, 7, 1, 3, 6, 9), [4, 7, 2, 9, 6, 3, 1]),
        (create(TreeNode, 2, 1, 3), [2, 3, 1]),
        (None, None),
    )

    class Test(unittest.TestCase):

        def test(self):
            invertTree = Solution().invertTree
            for root, excepted in CASES:
                actual = invertTree(root)
                actual = actual and actual.bfs()
                self.assertEqual(actual, excepted)

    unittest.main()

    invertTree = Solution().invertTree
    for root, excepted in CASES:
        print(timeit(lambda: invertTree(root), number=100000))
