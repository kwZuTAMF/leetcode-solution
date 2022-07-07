/*
[707. Design Linked List (Medium)](https://leetcode.com/problems/design-linked-list/)

@topic: Linked List
@topic: Design

Constraints:
  - `0 <= index, val <= 1000`
  - Please do not use the built-in LinkedList library.
  - At most `2000` calls will be made to `get`, `addAtHead`, `addAtTail`, `addAtIndex` and `deleteAtIndex`.
*/

struct Node {
    int val;
    Node* next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node* next) : val(x), next(next) {}
};

class MyLinkedList {
   private:
    int size;
    Node* head;

   public:
    MyLinkedList() {
        size = 0;
        head = new Node();
    }

    int get(int index) {
        if (index < 0 || index >= size) return -1;
        Node* curr = head->next;
        while (index--) curr = curr->next;
        return curr->val;
    }

    void addAtHead(int val) {
        addAtIndex(0, val);
    }

    void addAtTail(int val) {
        addAtIndex(size, val);
    }

    void addAtIndex(int index, int val) {
        if (index > size) return;
        if (index < 0) index = 0;
        Node* curr = head;
        while (index--) curr = curr->next;
        curr->next = new Node(val, curr->next);
        ++size;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        Node* curr = head;
        while (index--) curr = curr->next;
        Node* next = curr->next;
        curr->next = next->next;
        delete next;
        --size;
    }
};
