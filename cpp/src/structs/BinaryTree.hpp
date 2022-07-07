#pragma once

#include <queue>
#include <stack>
#include <vector>

using std::queue;
using std::reverse;
using std::stack;
using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

namespace BinaryTree {
    TreeNode* of(vector<int> items) {
        int n = items.size();
        if (n == 0) return nullptr;
        auto root = new TreeNode(items[0]);
        queue<TreeNode*> q;
        q.push(root);
        for (int i = 1; i < n; ++i) {
            auto node = q.front(); q.pop();
            if (items[i] != INT_MIN) q.push((node->left = new TreeNode(items[i])));
            if (++i == n) break;
            if (items[i] != INT_MIN) q.push((node->right = new TreeNode(items[i])));
        }
        return root;
    }

    vector<int> bfs(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        queue<TreeNode*> q;
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

    vector<int> preOrder(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode* cur = root;
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

    vector<int> inOrder(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode* cur = root;
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

    vector<int> postOrder(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode* pre = nullptr;
        TreeNode* cur = root;
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

    vector<int> morrisPreOrder(TreeNode* root) {
        vector<int> res;
        TreeNode* pre;
        TreeNode* cur = root;
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

    vector<int> morrisInOrder(TreeNode* root) {
        vector<int> res;
        TreeNode* pre;
        TreeNode* cur = root;
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

    vector<int> morrisPostOrder(TreeNode* root) {
        vector<int> res;
        TreeNode* pre;
        TreeNode* cur = root;
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
