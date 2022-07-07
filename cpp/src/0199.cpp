/*
[199. Binary Tree Right Side View (Medium)](https://leetcode.com/problems/binary-tree-right-side-view/)

@topic: Tree
@topic: Depth-First Search
@topic: Breadth-First Search
@topic: Binary Tree

Constraints:
  - The number of nodes in the tree is in the range `[0, 100]`.
  - `-100 <= Node.val <= 100`
*/

#include "structs/BinaryTree.hpp"

class Solution {
   public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        int n;
        while ((n = q.size())) {
            res.emplace_back(q.back()->val);
            while (n--) {
                auto node = q.front(); q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
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
        {of({1, 2, 3, INT_MIN, 5, INT_MIN, 4}), {1, 3, 4}},
        {of({1, INT_MIN, 3}), {1, 3}},
        {nullptr, {}},
    };

    for (auto& [root, excepted] : CASES) {
        assert(o.rightSideView(root) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [root, _] : CASES) {
        for (auto i = 0; i < 100000; ++i) {
            o.rightSideView(root);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
