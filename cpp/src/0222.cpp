/*
[222. Count Complete Tree Nodes (Medium)](https://leetcode.com/problems/count-complete-tree-nodes/)

@topic: Binary Search
@topic: Tree
@topic: Depth-First Search
@topic: Binary Tree

Constraints:
  - The number of nodes in the tree is in the range `[0, 5 * 10^4]`.
  - `0 <= Node.val <= 5 * 10^4`
  - The tree is guaranteed to be **complete**.
*/

#include "structs/BinaryTree.hpp"

class Solution {
   public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int level = 0;
        for (auto node = root; node->left; node = node->left) ++level;
        int lo = 1 << level;
        int hi = (1 << (level + 1)) - 1;
        while (lo < hi) {
            int mid = lo + ((hi - lo + 1) >> 1);
            if (exists(root, level, mid)) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        return lo;
    }

   private:
    bool exists(TreeNode* root, int level, int k) {
        auto bits = 1 << (level - 1);
        auto node = root;
        while (node && bits) {
            node = bits & k ? node->right : node->left;
            bits >>= 1;
        }
        return node != nullptr;
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

    vector<tuple<TreeNode*, int>> CASES = {
        {of({1, 2, 3, 4, 5, 6}), 6},
        {of({}), 0},
        {of({1}), 1},
    };

    for (auto& [root, excepted] : CASES) {
        assert(o.countNodes(root) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [root, _] : CASES) {
        for (auto i = 0; i < 100000; ++i) {
            o.countNodes(root);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
