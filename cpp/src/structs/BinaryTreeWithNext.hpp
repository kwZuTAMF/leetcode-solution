#pragma once

#include <queue>
#include <stack>
#include <vector>

using std::queue;
using std::reverse;
using std::stack;
using std::vector;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next) : val(_val), left(_left), right(_right), next(_next) {}
};

namespace BinaryTree {
    Node* of(vector<int> items) {
        int n = items.size();
        if (n == 0) return nullptr;
        auto root = new Node(items[0]);
        queue<Node*> q;
        q.push(root);
        for (int i = 1; i < n; ++i) {
            auto node = q.front(); q.pop();
            if (items[i] != INT_MIN) q.push((node->left = new Node(items[i])));
            if (++i == n) break;
            if (items[i] != INT_MIN) q.push((node->right = new Node(items[i])));
        }
        return root;
    }

    vector<int> bfs(Node* root) {
        if (!root) return {};
        vector<int> res;
        queue<Node*> q;
        q.push(root);
        int n;
        while ((n = q.size())) {
            auto node = q.front(); q.pop();
            res.emplace_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        return res;
    }

    vector<vector<int>> bfsByNext(Node* root) {
        if (!root) return {};
        vector<vector<int>> res;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            auto node = q.front(); q.pop();
            if (node->left)
                q.push(node->left);
            else if (node->right)
                q.push(node->right);
            res.emplace_back();
            while (node) {
                res.back().emplace_back(node->val);
                node = node->next;
            }
        }
        return res;
    }

    vector<int> preOrder(Node* root) {
        vector<int> res;
        stack<Node*> stk;
        Node* cur = root;
        while (cur || !stk.empty()) {
            while (cur) {
                res.emplace_back(cur->val);
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top()->right; stk.pop();
        }
        return res;
    }

    vector<int> inOrder(Node* root) {
        vector<int> res;
        stack<Node*> stk;
        Node* cur = root;
        while (cur || !stk.empty()) {
            while (cur) {
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top(); stk.pop();
            res.emplace_back(cur->val);
            cur = cur->right;
        }
        return res;
    }

    vector<int> postOrder(Node* root) {
        vector<int> res;
        stack<Node*> stk;
        Node* pre = nullptr;
        Node* cur = root;
        while (cur || !stk.empty()) {
            while (cur) {
                res.emplace_back(cur->val);
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top();
            if (cur->right && cur->right != pre) {
                cur = cur->right;
            } else {
                stk.pop();
                res.emplace_back(cur->val);
                pre = cur;
                cur = nullptr;
            }
        }
        return res;
    }

    vector<int> morrisPreOrder(Node* root) {
        vector<int> res;
        Node* pre;
        Node* cur = root;
        while (cur) {
            if ((pre = cur->left)) {
                while (pre->right && pre->right != cur) {
                    pre = pre->right;
                }
                if (!pre->right) {
                    res.emplace_back(cur->val);
                    pre->right = cur;
                    cur = cur->left;
                } else {
                    pre->right = nullptr;
                    cur = cur->right;
                }
            } else {
                res.emplace_back(cur->val);
                cur = cur->right;
            }
        }
        return res;
    }

    vector<int> morrisInOrder(Node* root) {
        vector<int> res;
        Node* pre;
        Node* cur = root;
        while (cur) {
            if ((pre = cur->left)) {
                while (pre->right && pre->right != cur) {
                    pre = pre->right;
                }
                if (!pre->right) {
                    pre->right = cur;
                    cur = cur->left;
                } else {
                    res.emplace_back(cur->val);
                    pre->right = nullptr;
                    cur = cur->right;
                }
            } else {
                res.emplace_back(cur->val);
                cur = cur->right;
            }
        }
        return res;
    }

    vector<int> morrisPostOrder(Node* root) {
        vector<int> res;
        Node* pre;
        Node* cur = root;
        while (cur) {
            if ((pre = cur->right)) {
                while (pre->left && pre->left != cur) {
                    pre = pre->left;
                }
                if (!pre->left) {
                    res.emplace_back(cur->val);
                    pre->left = cur;
                    cur = cur->right;
                } else {
                    pre->left = nullptr;
                    cur = cur->left;
                }
            } else {
                res.emplace_back(cur->val);
                cur = cur->left;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
}
