/*
[110. Balanced Binary Tree (Easy)](https://leetcode.com/problems/balanced-binary-tree/)

@topic: Tree
@topic: Depth-First Search
@topic: Binary Tree

Constraints:
  - The number of nodes in the tree is in the range `[0, 5000]`.
  - `-10^4 <= Node.val <= 10^4`
*/

#include "structs/BinaryTree.hpp"

using std::abs;
using std::max;

class Solution {
   public:
    bool isBalanced(TreeNode* root) {
        return ~dfs(root);
    }

   private:
    int dfs(TreeNode* root) {
        if (!root) return 0;
        int x = dfs(root->left), y;
        return ~x && ~(y = dfs(root->right)) && abs(x - y) <= 1 ? max(x, y) + 1 : -1;
    }

   /* public:
    bool isBalanced(TreeNode* root) {
        return !root || (abs(height(root->left) - height(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right));
    }

   private:
    int height(TreeNode* root) {
        return root ? max(height(root->left), height(root->right)) + 1 : 0;
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
        {of({3, 9, 20, INT_MIN, INT_MIN, 15, 7}), true},
        {of({1, 2, 2, 3, 3, INT_MIN, INT_MIN, 4, 4}), false},
        {of({}), true},
    };

    for (auto& [root, excepted] : CASES) {
        assert(o.isBalanced(root) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [root, _] : CASES) {
        for (auto i = 0; i < 100000; ++i) {
            o.isBalanced(root);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
