/*
[100. Same Tree (Easy)](https://leetcode.com/problems/same-tree/)

@topic: Tree
@topic: Depth-First Search
@topic: Breadth-First Search
@topic: Binary Tree

Constraints:
  - The number of nodes in both trees is in the range `[0, 100]`.
  - `-10^4 <= Node.val <= 10^4`
*/

#include "structs/BinaryTree.hpp"

class Solution {
   public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return p && q ? p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right) : p == q;
    }

    // bool isSameTree(TreeNode* p, TreeNode* q) {
    //     stack<TreeNode*> stk;
    //     while (p || q || stk.size()) {
    //         while (p || q) {
    //             if (!p || !q || p->val != q->val) return false;
    //             stk.push(p);
    //             stk.push(q);
    //             p = p->left;
    //             q = q->left;
    //         }
    //         q = stk.top()->right; stk.pop();
    //         p = stk.top()->right; stk.pop();
    //     }
    //     return true;
    // }

    // bool isSameTree(TreeNode* p, TreeNode* q) {
    //     queue<TreeNode*> que;
    //     que.push(p);
    //     que.push(q);
    //     while (que.size()) {
    //         p = que.front(); que.pop();
    //         q = que.front(); que.pop();
    //         if (!p && !q) continue;
    //         if (!p || !q || p->val != q->val) return false;
    //         que.push(p->left);
    //         que.push(q->left);
    //         que.push(p->right);
    //         que.push(q->right);
    //     }
    //     return true;
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

    vector<tuple<TreeNode*, TreeNode*, bool>> CASES = {
        {of({1, 2, 3}), of({1, 2, 3}), true},
        {of({1, 2}), of({1, INT_MIN, 2}), false},
        {of({1, 2, 1}), of({1, 1, 2}), false},
    };

    for (auto& [p, q, excepted] : CASES) {
        assert(o.isSameTree(p, q) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [p, q, _] : CASES) {
        for (auto i = 0; i < 100000; ++i) {
            o.isSameTree(p, q);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
