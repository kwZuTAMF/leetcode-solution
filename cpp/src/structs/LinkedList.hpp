#pragma once

#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

namespace LinkedList {
    using std::vector;

    ListNode* of(vector<int> items) {
        auto fake = ListNode();
        auto curr = &fake;
        for (int i : items) {
            curr->next = new ListNode(i);
            curr = curr->next;
        }
        return fake.next;
    }

    ListNode* cycle(std::vector<int> items, int pos) {
        auto fake = ListNode();
        auto curr = &fake;
        for (int i : items) {
            curr->next = new ListNode(i);
            curr = curr->next;
        }
        if (~pos) {
            auto last = fake.next;
            while (pos--) last = last->next;
            auto node = last;
            while (last->next) last = last->next;
            last->next = node;
        }
        return fake.next;
    }

    bool eq(ListNode* p, ListNode* q) {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr || p->val != q->val) return false;
        return eq(p->next, q->next);
    }

    void show(ListNode* head) {
        if (auto curr = head) {
            printf("%d", curr->val);
            curr = curr->next;
            while (curr) {
                printf("->%d", curr->val);
                curr = curr->next;
            }
            printf("\n");
        }
    }
};
