#pragma once

#include <queue>
#include <vector>

using std::queue;
using std::vector;

class Node {
   public:
    int val;
    vector<Node*> children;
    Node() {}
    Node(int _val) { val = _val; }
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

namespace NaryTree {
    Node* of(vector<int> items) {
        int n = items.size();
        if (n == 0) return nullptr;
        auto fake = Node();
        queue<Node*> q;
        q.push(&fake);
        for (int i = 0; i < n; ++i) {
            auto parent = q.front();
            q.pop();
            parent->children = {};
            while (i < n && items[i] != INT_MIN) {
                auto child = new Node(items[i]);
                parent->children.emplace_back(child);
                q.push(child);
                ++i;
            }
        }
        return fake.children.front();
    }

    vector<vector<int>> bfs(Node* root) {
        vector<vector<int>> res;
        queue<Node*> q;
        q.push(root);
        int n;
        while ((n = q.size())) {
            res.emplace_back();
            while (n--) {
                auto parent = q.front();
                q.pop();
                res.back().emplace_back(parent->val);
                for (auto child : parent->children) {
                    q.push(child);
                }
            }
        }
        return res;
    }
}
