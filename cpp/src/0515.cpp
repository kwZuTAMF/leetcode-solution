/*
[515. Find Largest Value in Each Tree Row (Medium)](https://leetcode.com/problems/find-largest-value-in-each-tree-row/)

@topic: Tree
@topic: Depth-First Search
@topic: Breadth-First Search
@topic: Binary Tree

Constraints:
  - The number of nodes in the tree will be in the range `[0, 10^4]`.
  - `-2^31 <= Node.val <= 2^31 - 1`
*/

#include <queue>

#include "structs/BinaryTree.hpp"

using std::max;
using std::queue;

class Solution {
   public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if (root) {
            queue<TreeNode*> q;
            q.push(root);
            int n;
            while ((n = q.size())) {
                int m = INT_MIN;
                for (int i = 0; i < n; ++i) {
                    auto node = q.front(); q.pop();
                    m = max(m, node->val);
                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                }
                res.emplace_back(m);
            }
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

    vector<tuple<TreeNode*, vector<int>>> CASES = {
        {of({1, 3, 2, 5, 3, INT_MIN, 9}), {1, 3, 9}},
        {of({1, 2, 3}), {1, 3}},
    };

    for (auto& [root, excepted] : CASES) {
        assert(o.largestValues(root) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [root, _] : CASES) {
        for (auto i = 0; i < 100000; ++i) {
            o.largestValues(root);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
