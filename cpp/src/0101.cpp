/*
[101. Symmetric Tree (Easy)](https://leetcode.com/problems/symmetric-tree/)

@topic: Tree
@topic: Depth-First Search
@topic: Breadth-First Search
@topic: Binary Tree

Constraints:
  - The number of nodes in the tree is in the range `[1, 1000]`.
  - `-100 <= Node.val <= 100`
*/

#include "structs/BinaryTree.hpp"

class Solution {
   public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root->left);
        que.push(root->right);
        while (!que.empty()) {
            TreeNode* p = que.front(); que.pop();
            TreeNode* q = que.front(); que.pop();
            if (!p && !q) continue;
            if (!p || !q || p->val != q->val) return false;
            que.push(p->left);
            que.push(q->right);
            que.push(p->right);
            que.push(q->left);
        }
        return true;
    }

    /* bool isSymmetric(TreeNode* root) {
        return dfs(root->left, root->right);
    }

   private:
    bool dfs(TreeNode* p, TreeNode* q) {
        return p && q ? p->val == q->val && dfs(p->left, q->right) && dfs(p->right, q->left) : p == q;
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

    vector<tuple<TreeNode*, bool>> CASES = {
        {of({1, 2, 2, 3, 4, 4, 3}), true},
        {of({1, 2, 2, INT_MIN, 3, INT_MIN, 3}), false},
    };

    for (auto& [root, excepted] : CASES) {
        assert(o.isSymmetric(root) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [root, _] : CASES) {
        for (auto i = 0; i < 100000; ++i) {
            o.isSymmetric(root);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
