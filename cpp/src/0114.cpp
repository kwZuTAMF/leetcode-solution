/*
[114. Flatten Binary Tree to Linked List (Medium)](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/)

@topic: Linked List
@topic: Stack
@topic: Tree
@topic: Depth-First Search
@topic: Binary Tree

Constraints:
  - The number of nodes in the tree is in the range `[0, 2000]`.
  - `-100 <= Node.val <= 100`
*/

#include "structs/BinaryTree.hpp"

class Solution {
   public:
    void flatten(TreeNode* root) {
        auto curr = root;
        while (curr) {
            if (curr->left) {
                auto next = curr->left;
                auto prev = next;
                while (prev->right) {
                    prev = prev->right;
                }
                prev->right = curr->right;
                curr->left = nullptr;
                curr->right = next;
            }
            curr = curr->right;
        }
    }

    // void flatten(TreeNode* root) {
    //     if (!root) return;
    //     stack<TreeNode*> stk;
    //     stk.push(root);
    //     TreeNode* prev = nullptr;
    //     while (!stk.empty()) {
    //         auto curr = stk.top(); stk.pop();
    //         if (prev) {
    //             prev->left = nullptr;
    //             prev->right = curr;
    //         }
    //         if (curr->right) stk.push(curr->right);
    //         if (curr->left) stk.push(curr->left);
    //         prev = curr;
    //     }
    // }

    // void flatten(TreeNode* root) {
    //     if (!root) return;
    //     flatten(root->left);
    //     auto right = root->right;
    //     root->right = root->left;
    //     root->left = nullptr;
    //     while (root->right) root = root->right;
    //     flatten(right);
    //     root->right = right;
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

    vector<tuple<TreeNode*, TreeNode*>> CASES = {
        {of({1, 2, 5, 3, 4, INT_MIN, 6}), of({1, INT_MIN, 2, INT_MIN, 3, INT_MIN, 4, INT_MIN, 5, INT_MIN, 6})},
        {of({}), of({})},
        {of({0}), of({0})},
    };

    for (auto& [root, excepted] : CASES) {
        o.flatten(root);
        assert(bfs(root) == bfs(excepted));
    }

    auto start = system_clock::now();
    for (auto i = 0; i < 100000; ++i) {
        o.flatten(of({1, 2, 5, 3, 4, INT_MIN, 6}));
        o.flatten(of({}));
        o.flatten(of({0}));
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
