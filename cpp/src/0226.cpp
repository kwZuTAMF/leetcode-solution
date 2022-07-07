/*
[226. Invert Binary Tree (Easy)](https://leetcode.com/problems/invert-binary-tree/)

@topic: Tree
@topic: Depth-First Search
@topic: Breadth-First Search
@topic: Binary Tree

Constraints:
  - The number of nodes in the tree is in the range `[0, 100]`.
  - `-100 <= Node.val <= 100`
*/

#include <queue>
#include <stack>

#include "structs/BinaryTree.hpp"

using std::queue;
using std::stack;
using std::swap;

class Solution {
   public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            auto node = q.front(); q.pop();
            swap(node->left, node->right);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        return root;
    }

    // TreeNode* invertTree(TreeNode* root) {
    //     if (!root) return nullptr;
    //     auto cur = root;
    //     stack<TreeNode*> stk;
    //     while (cur || !stk.empty()) {
    //         while (cur) {
    //             swap(cur->left, cur->right);
    //             stk.push(cur);
    //             cur = cur->left;
    //         }
    //         cur = stk.top()->right; stk.pop();
    //     }
    //     return root;
    // }

    // TreeNode* invertTree(TreeNode* root) {
    //     if (!root) return nullptr;
    //     swap(root->left, root->right);
    //     if (root->left) invertTree(root->left);
    //     if (root->right) invertTree(root->right);
    //     return root;
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
        {of({4, 2, 7, 1, 3, 6, 9}), {4, 7, 2, 9, 6, 3, 1}},
        {of({2, 1, 3}), {2, 3, 1}},
        {nullptr, {}},
    };

    for (auto& [root, excepted] : CASES) {
        o.invertTree(root);
        assert(bfs(root) == excepted);
    }

    auto start = system_clock::now();
    for (auto i = 0; i < 100000; ++i) {
        o.invertTree(of({4, 2, 7, 1, 3, 6, 9}));
        o.invertTree(of({2, 1, 3}));
        o.invertTree(nullptr);
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
