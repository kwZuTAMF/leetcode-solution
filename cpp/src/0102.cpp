/*
[102. Binary Tree Level Order Traversal (Medium)](https://leetcode.com/problems/binary-tree-level-order-traversal/)

@topic: Tree
@topic: Breadth-First Search
@topic: Binary Tree

Constraints:
  - The number of nodes in the tree is in the range `[0, 2000]`.
  - `-1000 <= Node.val <= 1000`
*/

#include "structs/BinaryTree.hpp"

class Solution {
   public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        int n;
        while ((n = q.size())) {
            res.emplace_back();
            for (int i = 0; i < n; ++i) {
                auto node = q.front(); q.pop();
                res.back().emplace_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return res;
    }

    /* vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (root) dfs(root, 0, res);
        return res;
    }

   private:
    void dfs(TreeNode *root, size_t depth, vector<vector<int>> &res) {
        if (depth == res.size()) res.emplace_back();
        res.back().emplace_back(root->val);
        if (root->left) dfs(root->left, depth + 1, res);
        if (root->right) dfs(root->right, depth + 1, res);
    } */
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

    vector<tuple<TreeNode *, vector<vector<int>>>> CASES = {
        {of({3, 9, 20, INT_MIN, INT_MIN, 15, 7}), {{3}, {9, 20}, {15, 7}}},
        {of({1}), {{1}}},
        {nullptr, {}},
    };

    for (auto &[root, excepted] : CASES) {
        assert(o.levelOrder(root) == excepted);
    }

    auto start = system_clock::now();
    for (auto &[root, _] : CASES) {
        for (auto i = 0; i < 100000; ++i) {
            o.levelOrder(root);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
