/*
[94. Binary Tree Inorder Traversal (Easy)](https://leetcode.com/problems/binary-tree-inorder-traversal/)

@topic: Stack
@topic: Tree
@topic: Depth-First Search
@topic: Binary Tree

Constraints:
  - The number of nodes in the tree is in the range `[0, 100]`.
  - `-100 <= Node.val <= 100`
*/

#include "structs/BinaryTree.hpp"

class Solution {
   public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        TreeNode *pre;
        TreeNode *cur = root;
        while (cur) {
            if ((pre = cur->left)) {
                while (pre->right && pre->right != cur) {
                    pre = pre->right;
                }
                if (pre->right == nullptr) {
                    pre->right = cur;
                    cur = cur->left;
                } else {
                    res.emplace_back(cur->val);
                    pre->right = nullptr;
                    cur = cur->right;
                }
            } else {
                res.emplace_back(cur->val);
                cur = cur->right;
            }
        }
        return res;
    }

    // vector<int> inorderTraversal(TreeNode *root) {
    //     if (!root) return {};
    //     vector<int> res;
    //     stack<TreeNode *> stk;
    //     TreeNode *cur = root;
    //     while (cur || !stk.empty()) {
    //         while (cur) {
    //             stk.push(cur);
    //             cur = cur->left;
    //         }
    //         cur = stk.top(); stk.pop();
    //         res.emplace_back(cur->val);
    //         cur = cur->right;
    //     }
    //     return res;
    // }
};

#include <cassert>
#include <chrono>
#include <iostream>

using std::tuple;
using std::chrono::duration_cast;
using std::chrono::microseconds;
using std::chrono::system_clock;

int main() {
    using namespace BinaryTree;

    Solution o;

    vector<tuple<TreeNode*, vector<int>>> CASES = {
        {of({1, INT_MIN, 2, 3}), {1, 3, 2}},
        {nullptr, {}},
        {of({1}), {1}},
    };

    for (auto& [root, excepted] : CASES) {
        assert(o.inorderTraversal(root) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [root, _] : CASES) {
        for (auto i = 0; i < 100000; ++i) {
            o.inorderTraversal(root);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
