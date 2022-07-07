/*
[257. Binary Tree Paths (Easy)](https://leetcode.com/problems/binary-tree-paths/)

@topic: String
@topic: Backtracking
@topic: Tree
@topic: Depth-First Search
@topic: Binary Tree

Constraints:
  - The number of nodes in the tree is in the range `[1, 100]`.
  - `-100 <= Node.val <= 100`
*/

#include <string>
#include <vector>

#include "structs/BinaryTree.hpp"

using std::string;
using std::to_string;
using std::vector;

class Solution {
   public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        dfs(root, "", paths);
        return paths;
    }

   private:
    void dfs(TreeNode* root, string path, vector<string>& paths) {
        if (!root) return;
        path += to_string(root->val);
        if (!root->left && !root->right) {
            paths.emplace_back(path);
        } else {
            path += "->";
            dfs(root->left, path, paths);
            dfs(root->right, path, paths);
        }
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

    vector<tuple<TreeNode*, vector<string>>> CASES = {
        {of({1, 2, 3, INT_MIN, 5}), {"1->2->5", "1->3"}},
        {of({1}), {"1"}},
    };

    for (auto& [root, excepted] : CASES) {
        assert(o.binaryTreePaths(root) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [root, _] : CASES) {
        for (auto i = 0; i < 100000; ++i) {
            o.binaryTreePaths(root);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
