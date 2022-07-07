/*
[116. Populating Next Right Pointers in Each Node (Medium)](https://leetcode.com/problems/populating-next-right-pointers-in-each-node/)

@topic: Linked List
@topic: Tree
@topic: Depth-First Search
@topic: Breadth-First Search
@topic: Binary Tree

Constraints:
  - The number of nodes in the tree is in the range ``[0, 2^12 - 1]`.
  - `-1000 <= Node.val <= 1000`
*/

#include "structs/BinaryTreeWithNext.hpp"

class Solution {
   public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        queue<Node*> q;
        q.push(root);
        int n;
        while ((n = q.size())) {
            while (n--) {
                Node* node = q.front(); q.pop();
                if (n) node->next = q.front();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return root;
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

    vector<tuple<Node*, vector<vector<int>>>> CASES = {
        {of({1, 2, 3, 4, 5, 6, 7}), {{1}, {2, 3}, {4, 5, 6, 7}}},
        {nullptr, {}},
    };

    for (auto& [root, excepted] : CASES) {
        assert(bfsByNext(o.connect(root)) == excepted);
    }

    auto start = system_clock::now();
    for (auto i = 0; i < 100000; ++i) {
        o.connect(of({1, 2, 3, 4, 5, 6, 7}));
        o.connect(nullptr);
    }
    auto end = system_clock::now();
    std::cout << duration_cast<microseconds>(end - start).count() << std::endl;
}
