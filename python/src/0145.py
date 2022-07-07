# [145. Binary Tree Postorder Traversal (Easy)](https://leetcode.com/problems/binary-tree-postorder-traversal/)
# @topic Stack
# @topic Tree
# @topic Depth-First Search
# @topic Binary Tree
#
# Constraints:
# The number of the nodes in the tree is in the range [0, 100].
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

    # def postorderTraversal(self, root: Optional[TreeNode]) -> list[int]:
    #     def dfs(root, res):
    #         if root:
    #             root.left and dfs(root.left, res)
    #             root.right and dfs(root.right, res)
    #             res.append(root.val)
    #         return res
    #     return dfs(root, []) if root else []

    def postorderTraversal(self, root: Optional[TreeNode]) -> list[int]:
        res = []
        pre = None
        cur = root
        stk = deque()
        while cur or stk:
            while cur:
                stk.append(cur)
                cur = cur.left
            cur = stk[-1]
            if cur.right and cur.right != pre:
                cur = cur.right
            else:
                stk.pop()
                res.append(cur.val)
                pre = cur
                cur = None
        return res

    # def postorderTraversal(self, root: Optional[TreeNode]) -> list[int]:
    #     res = []
    #     cur = root
    #     while cur:
    #         if pre := cur.right:
    #             while pre.left and pre.left != cur:
    #                 pre = pre.left
    #             if not pre.left:
    #                 res.append(cur.val)
    #                 pre.left = cur
    #                 cur = cur.right
    #             else:
    #                 pre.left = None
    #                 cur = cur.left
    #         else:
    #             res.append(cur.val)
    #             cur = cur.left
    #     return res[::-1]

    # def postorderTraversal(self, root: Optional[TreeNode]) -> list[int]:
    #     res = []
    #     cur = root
    #     while cur:
    #         res.append(cur.val)
    #         if pre := cur.right:
    #             while pre.left:
    #                 pre = pre.left
    #             pre.left = cur.left
    #             pre = cur
    #             cur = cur.right
    #             pre.left = None
    #             pre.right = None
    #         else:
    #             cur = cur.left
    #     return res[::-1]


if __name__ == '__main__':
    import unittest
    from timeit import timeit

    CASES = (
        (create(TreeNode, 1, None, 2, 3), [3, 2, 1]),
        (None, []),
        (TreeNode(1), [1]),
    )

    class Test(unittest.TestCase):

        def test(self):
            postorderTraversal = Solution().postorderTraversal
            for root, excepted in CASES:
                actual = postorderTraversal(root)
                self.assertEqual(actual, excepted)

    unittest.main()

    postorderTraversal = Solution().postorderTraversal
    for root, excepted in CASES:
        print(timeit(lambda: postorderTraversal(root), number=100000))
