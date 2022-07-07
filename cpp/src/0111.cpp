/*
[111. Minimum Depth of Binary Tree (Easy)](https://leetcode.com/problems/minimum-depth-of-binary-tree/)

@topic: Tree
@topic: Depth-First Search
@topic: Breadth-First Search
@topic: Binary Tree

Constraints:
  - The number of nodes in the tree is in the range `[0, 10^5]`.
  - `-1000 <= Node.val <= 1000`
*/

#include "structs/BinaryTree.hpp"

using std::min;

class Solution {
   public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        int depth = 0;
        queue<TreeNode*> q;
        q.push(root);
        int n;
        while ((n = q.size())) {
            ++depth;
            while (n--) {
                auto node = q.front(); q.pop();
                if (!node->left && !node->right) return depth;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return depth;
    }

    // int minDepth(TreeNode* root) {
    //     if (!root) return 0;
    //     if (!root->left) return minDepth(root->right) + 1;
    //     if (!root->right) return minDepth(root->left) + 1;
    //     return min(minDepth(root->left), minDepth(root->right)) + 1;
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
        {of({3, 9, 20, INT_MIN, INT_MIN, 15, 7}), 2},
        {of({2, INT_MIN, 3, INT_MIN, 4, INT_MIN, 5, INT_MIN, 6}), 5},
    };

    for (auto& [root, excepted] : CASES) {
        assert(o.minDepth(root) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [root, _] : CASES) {
        for (auto i = 0; i < 100000; ++i) {
            o.minDepth(root);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
