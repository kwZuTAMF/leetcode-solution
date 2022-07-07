/*
[572. Subtree of Another Tree (Easy)](https://leetcode.com/problems/subtree-of-another-tree/)

@topic: Tree
@topic: Depth-First Search
@topic: String Matching
@topic: Binary Tree
@topic: Hash Function

Constraints:
  - The number of nodes in the `root` tree is in the range `[1, 2000]`.
  - The number of nodes in the `subRoot` tree is in the range `[1, 1000]`.
  - `-10^4 <= root.val <= 10^4`
  - `-10^4 <= subRoot.val <= 10^4`
*/

#include "structs/BinaryTree.hpp"

class Solution {
   public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return isSameTree(root, subRoot) || isSameTree(root->left, subRoot) || isSameTree(root->right, subRoot);
    }

   private:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return p && q ? p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right) : p == q;
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

    vector<tuple<TreeNode*, TreeNode*, bool>> CASES = {
        {of({3, 4, 5, 1, 2}), of({4, 1, 2}), true},
        {of({3, 4, 5, 1, 2, INT_MIN, INT_MIN, INT_MIN, INT_MIN, 0}), of({4, 1, 2}), false},
    };

    for (auto& [root, subRoot, excepted] : CASES) {
        assert(o.isSubtree(root, subRoot) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [root, subRoot, _] : CASES) {
        for (auto i = 0; i < 100000; ++i) {
            o.isSubtree(root, subRoot);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
