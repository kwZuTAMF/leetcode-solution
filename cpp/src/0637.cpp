/*
[637. Average of Levels in Binary Tree (Easy)](https://leetcode.com/problems/average-of-levels-in-binary-tree/)

@topic: Tree
@topic: Depth-First Search
@topic: Breadth-First Search
@topic: Binary Tree

Constraints:
  - The number of nodes in the tree is in the range `[1, 10^4]`.
  - `-2^31 <= Node.val <= 2^31 - 1`
*/

#include <queue>

#include "structs/BinaryTree.hpp"

using std::queue;

class Solution {
   public:
    vector<double> averageOfLevels(TreeNode* root) {
        if (!root) return {};
        vector<double> res;
        queue<TreeNode*> q;
        q.push(root);
        int n;
        while ((n = q.size())) {
            double sum = 0;
            for (int i = 0; i < n; ++i) {
                auto node = q.front(); q.pop();
                sum += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res.emplace_back(sum / n);
        }
        return res;
    }
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

    vector<tuple<TreeNode*, vector<double>>> CASES = {
        {of({3, 9, 20, INT_MIN, INT_MIN, 15, 7}), {3.00000, 14.50000, 11.00000}},
        {of({3, 9, 20, 15, 7}), vector<double>{{3.00000, 14.50000, 11.00000}}},
    };

    for (auto& [root, excepted] : CASES) {
        assert(o.averageOfLevels(root) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [root, _] : CASES) {
        for (auto i = 0; i < 100000; ++i) {
            o.averageOfLevels(root);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
