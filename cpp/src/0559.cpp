/*
[559. Maximum Depth of N-ary Tree (Easy)](https://leetcode.com/problems/maximum-depth-of-n-ary-tree/)

@topic: Tree
@topic: Depth-First Search
@topic: Breadth-First Search

Constraints:
  - The total number of nodes is in the range `[0, 10^4]`.
  - The depth of the n-ary tree is less than or equal to `1000`.
*/

#include "structs/NaryTree.hpp"

using std::max;

class Solution {
   public:
    int maxDepth(Node* root) {
        if (!root) return 0;
        int depth = 0;
        queue<Node*> q;
        q.push(root);
        int n;
        while ((n = q.size())) {
            ++depth;
            while (n--) {
                Node* parent = q.front(); q.pop();
                for (Node* child : parent->children) {
                    q.push(child);
                }
            }
        }
        return depth;
    }

    // int maxDepth(Node* root) {
    //     if (!root) return 0;
    //     int depth = 0;
    //     for (Node* child : root->children) depth = max(depth, maxDepth(child));
    //     return depth + 1;
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
    using namespace NaryTree;

    Solution o;

    vector<tuple<Node*, int>> CASES = {
        {of({1, INT_MIN, 3, 2, 4, INT_MIN, 5, 6}), 3},
        {of({1, INT_MIN, 2, 3, 4, 5, INT_MIN, INT_MIN, 6, 7, INT_MIN, 8, INT_MIN, 9, 10, INT_MIN, INT_MIN, 11, INT_MIN, 12, INT_MIN, 13, INT_MIN, INT_MIN, 14}), 5},
    };

    for (auto& [root, excepted] : CASES) {
        assert(o.maxDepth(root) == excepted);
    }

    auto start = system_clock::now();
    for (auto& [root, _] : CASES) {
        for (int i = 0; i < 100000; ++i) {
            o.maxDepth(root);
        }
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
