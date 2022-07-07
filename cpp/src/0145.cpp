/*
[145. Binary Tree Postorder Traversal (Easy)](https://leetcode.com/problems/binary-tree-postorder-traversal/)

@topic: Stack
@topic: Tree
@topic: Depth-First Search
@topic: Binary Tree

Constraints:
  - The number of the nodes in the tree is in the range `[0, 100]`.
  - `-100 <= Node.val <= 100`
*/


#include "structs/BinaryTree.hpp"

class Solution {
   public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        TreeNode *pre;
        TreeNode *cur = root;
        while (cur) {
            if ((pre = cur->right)) {
                while (pre->left && pre->left != cur) {
                    pre = pre->left;
                }
                if (pre->left == nullptr) {
                    res.emplace_back(cur->val);
                    pre->left = cur;
                    cur = cur->right;
                } else {
                    pre->left = nullptr;
                    cur = cur->left;
                }
            } else {
                res.emplace_back(cur->val);
                cur = cur->left;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }

    // vector<int> postorderTraversal(TreeNode *root) {
    //     if (!root) return {};
    //     vector<int> res;
    //     stack<TreeNode *> stk;
    //     TreeNode *pre = nullptr;
    //     TreeNode *cur = root;
    //     while (cur || !stk.empty()) {
    //         while (cur) {
    //             stk.push(cur);
    //             cur = cur->left;
    //         }
    //         cur = stk.top();
    //         if (cur->right && cur->right != pre) {
    //             cur = cur->right;
    //         } else {
    //             stk.pop();
    //             res.emplace_back(cur->val);
    //             pre = cur;
    //             cur = nullptr;
    //         }
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
        {of({1, INT_MIN, 2, 3}), {3, 2, 1}},
        {nullptr, {}},
        {of({1}), {1}},
    };

    for (auto& [root, excepted] : CASES) {
        assert(o.postorderTraversal(root) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [root, _] : CASES) {
        for (auto i = 0; i < 100000; ++i) {
            o.postorderTraversal(root);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;

}
