# [102. Binary Tree Level Order Traversal (Medium)](https://leetcode.com/problems/binary-tree-level-order-traversal/)
# @topic Tree
# @topic Breadth-First Search
# @topic Binary Tree
#
# Constraints:
# The number of the nodes in the tree is in the range [0, 100].
# -100 <= Node.val <= 100

from typing import Optional

from structs.BinaryTree import create, TreeNode


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def levelOrder(self, root: Optional[TreeNode]) -> list[list[int]]:
        return self.__dfs(root, 0, []) if root else []

    def __dfs(self, root: Optional[TreeNode], i: int, res: list[list[int]]) -> list[list[int]]:
        i == len(res) and res.append([])
        res[i].append(root.val)
        root.left and self.__dfs(root.left, i + 1, res)
        root.right and self.__dfs(root.right, i + 1, res)
        return res


if __name__ == '__main__':
    import unittest
    from timeit import timeit

    CASES = (
        (create(TreeNode, 3, 9, 20, None, None, 15, 7), [[3], [9, 20], [15, 7]]),
        (TreeNode(1), [[1]]),
        (None, []),
    )

    class Test(unittest.TestCase):

        def test(self):
            levelOrder = Solution().levelOrder
            for root, excepted in CASES:
                actual = levelOrder(root)
                self.assertEqual(actual, excepted)

    unittest.main()

    levelOrder = Solution().levelOrder
    for root, excepted in CASES:
        print(timeit(lambda: levelOrder(root), number=100000))
