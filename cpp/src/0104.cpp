/*
[104. Maximum Depth of Binary Tree (Easy)](https://leetcode.com/problems/maximum-depth-of-binary-tree/)

@topic: Tree
@topic: Depth-First Search
@topic: Breadth-First Search
@topic: Binary Tree

Constraints:
  - The number of nodes in the tree is in the range `[0, 10^4]`.
  - `-100 <= Node.val <= 100`
*/

#include "structs/BinaryTree.hpp"

using std::max;

class Solution {
   public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        int depth = 0;
        queue<TreeNode*> q;
        q.push(root);
        int n;
        while ((n = q.size())) {
            ++depth;
            while (n--) {
                auto node = q.front(); q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return depth;
    }

    // int maxDepth(TreeNode* root) {
    //     return root ? max(maxDepth(root->left), maxDepth(root->right)) + 1 : 0;
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

    vector<tuple<TreeNode*, int>> CASES = {
        {of({3, 9, 20, INT_MIN, INT_MIN, 15, 7}), 3},
        {of({1, INT_MIN, 2}), 2},
    };

    for (auto& [root, excepted] : CASES) {
        assert(o.maxDepth(root) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [root, _] : CASES) {
        for (auto i = 0; i < 100000; ++i) {
            o.maxDepth(root);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
