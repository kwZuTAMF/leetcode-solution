/*
[117. Populating Next Right Pointers in Each Node II (Medium)](https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/)

@topic: Linked List
@topic: Tree
@topic: Depth-First Search
@topic: Breadth-First Search
@topic: Binary Tree

Constraints:
  - The number of nodes in the tree is in the range `[0, 6000]`.
  - `-100 <= Node.val <= 100`
*/

#include "structs/BinaryTreeWithNext.hpp"

class Solution {
   public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        auto fake = Node();
        auto prev = &fake;
        auto curr = root;
        while (curr) {
            if (curr->left) {
                prev->next = curr->left;
                prev = prev->next;
            }
            if (curr->right) {
                prev->next = curr->right;
                prev = prev->next;
            }
            if (!(curr = curr->next)) {
                curr = fake.next;
                fake.next = nullptr;
                prev = &fake;
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
        {of({1, 2, 3, 4, 5, INT_MIN, 7}), {{1}, {2, 3}, {4, 5, 7}}},
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
