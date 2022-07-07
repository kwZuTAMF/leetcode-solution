package structs.util;

import structs.linkedlist.ListNode;

public class LinkedList {
    public static ListNode of(int... items) {
        var fake = new ListNode();
        var curr = fake;
        for (var item : items)
            curr = curr.next = new ListNode(item);
        return fake.next;
    }
}
