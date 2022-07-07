# [144. Binary Tree Preorder Traversal (Easy)](https://leetcode.com/problems/binary-tree-preorder-traversal/)
# @topic Stack
# @topic Tree
# @topic Depth-First Search
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

    # def preorderTraversal(self, root: Optional[TreeNode]) -> list[int]:
    #     def dfs(root, res):
    #         if root:
    #             res.append(root.val)
    #             root.left and dfs(root.left, res)
    #             root.right and dfs(root.right, res)
    #         return res
    #     return dfs(root, []) if root else []

    def preorderTraversal(self, root: Optional[TreeNode]) -> list[int]:
        res = []
        cur = root
        stk = deque()
        while cur or stk:
            while cur:
                res.append(cur.val)
                stk.append(cur)
                cur = cur.left
            cur = stk.pop().right
        return res

    # def preorderTraversal(self, root: Optional[TreeNode]) -> list[int]:
    #     res = []
    #     cur = root
    #     while cur:
    #         if pre := cur.left:
    #             while pre.right and pre.right != cur:
    #                 pre = pre.right
    #             if not pre.right:
    #                 res.append(cur.val)
    #                 pre.right = cur
    #                 cur = cur.left
    #             else:
    #                 pre.right = None
    #                 cur = cur.right
    #         else:
    #             res.append(cur.val)
    #             cur = cur.right
    #     return res

    # def preorderTraversal(self, root: Optional[TreeNode]) -> list[int]:
    #     res = []
    #     cur = root
    #     while cur:
    #         res.append(cur.val)
    #         if pre := cur.left:
    #             while pre.right:
    #                 pre = pre.right
    #             pre.right = cur.right
    #             pre = cur
    #             cur = cur.left
    #             pre.left = None
    #             pre.right = None
    #         else:
    #             cur = cur.right
    #     return res


if __name__ == '__main__':
    import unittest
    from timeit import timeit

    CASES = (
        (create(TreeNode, 1, None, 2, 3), [1, 2, 3]),
        (None, []),
        (TreeNode(1), [1]),
    )

    class Test(unittest.TestCase):

        def test(self):
            preorderTraversal = Solution().preorderTraversal
            for root, excepted in CASES:
                actual = preorderTraversal(root)
                self.assertEqual(actual, excepted)

    unittest.main()

    preorderTraversal = Solution().preorderTraversal
    for root, excepted in CASES:
        print(timeit(lambda: preorderTraversal(root), number=100000))
