# [94. Binary Tree Inorder Traversal (Easy)](https://leetcode.com/problems/binary-tree-inorder-traversal/)
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

    # def inorderTraversal(self, root: Optional[TreeNode]) -> list[int]:
    #     def dfs(root, res):
    #         if root:
    #             root.left and dfs(root.left, res)
    #             res.append(root.val)
    #             root.right and dfs(root.right, res)
    #         return res
    #     return dfs(root, []) if root else []

    def inorderTraversal(self, root: Optional[TreeNode]) -> list[int]:
        res = []
        cur = root
        stk = deque()
        while cur or stk:
            while cur:
                stk.append(cur)
                cur = cur.left
            cur = stk.pop()
            res.append(cur.val)
            cur = cur.right
        return res

    # def inorderTraversal(self, root: Optional[TreeNode]) -> list[int]:
    #     res = []
    #     cur = root
    #     while cur:
    #         if pre := cur.left:
    #             while pre.right and pre.right != cur:
    #                 pre = pre.right
    #             if not pre.right:
    #                 pre.right = cur
    #                 cur = cur.left
    #             else:
    #                 res.append(cur.val)
    #                 pre.right = None
    #                 cur = cur.right
    #         else:
    #             res.append(cur.val)
    #             cur = cur.right
    #     return res

    # def inorderTraversal(self, root: Optional[TreeNode]) -> list[int]:
    #     res = []
    #     cur = root
    #     while cur:
    #         if pre := cur.left:
    #             while pre.right:
    #                 pre = pre.right
    #             pre.right = cur
    #             pre = cur
    #             cur = cur.left
    #             pre.left = None
    #         else:
    #             res.append(cur.val)
    #             cur = cur.right
    #     return res


if __name__ == '__main__':
    import unittest
    from timeit import timeit

    CASES = (
        (create(TreeNode, 1, None, 2, 3), [1, 3, 2]),
        (None, []),
        (TreeNode(1), [1]),
    )

    class Test(unittest.TestCase):

        def test(self):
            inorderTraversal = Solution().inorderTraversal
            for root, excepted in CASES:
                actual = inorderTraversal(root)
                self.assertEqual(actual, excepted)

    unittest.main()

    inorderTraversal = Solution().inorderTraversal
    for root, excepted in CASES:
        print(timeit(lambda: inorderTraversal(root), number=100000))
