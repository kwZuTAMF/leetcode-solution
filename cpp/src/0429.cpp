/*
[429. N-ary Tree Level Order Traversal (Medium)](https://leetcode.com/problems/n-ary-tree-level-order-traversal/)

@topic: Tree
@topic: Breadth-First Search

Constraints:
  - The height of the n-ary tree is less than or equal to `1000`
  - The total number of nodes is between `[0, 10^4]`
*/

#include "structs/NaryTree.hpp"

class Solution {
   public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return {};
        vector<vector<int>> res;
        queue<Node*> q;
        q.push(root);
        int n;
        while ((n = q.size())) {
            res.emplace_back();
            while (n--) {
                Node* parent = q.front(); q.pop();
                res.back().emplace_back(parent->val);
                for (Node* child : parent->children) {
                    q.push(child);
                }
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
    using namespace NaryTree;

    Solution o;

    vector<tuple<Node*, vector<vector<int>>>> CASES = {
        {of({1, INT_MIN, 3, 2, 4, INT_MIN, 5, 6}), {{1}, {3, 2, 4}, {5, 6}}},
        {of({1, INT_MIN, 2, 3, 4, 5, INT_MIN, INT_MIN, 6, 7, INT_MIN, 8, INT_MIN, 9, 10, INT_MIN, INT_MIN, 11, INT_MIN, 12, INT_MIN, 13, INT_MIN, INT_MIN, 14}), {{1}, {2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13}, {14}}},
    };

    for (auto& [root, excepted] : CASES) {
        assert(o.levelOrder(root) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [root, _] : CASES) {
        for (int i = 0; i < 100000; ++i) {
            o.levelOrder(root);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
