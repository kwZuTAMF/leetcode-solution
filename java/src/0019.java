import static org.assertj.core.api.Assertions.assertThat;
import static structs.util.LinkedList.of;

import java.time.Instant;
import java.time.temporal.ChronoUnit;

import structs.linkedlist.ListNode;

/**
* Definition for singly-linked list.
* public class ListNode {
*     int val;
*     ListNode next;
*     ListNode() {}
*     ListNode(int val) { this.val = val; }
*     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
* }
*/
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        var slow = head;
        var fast = head;
        while (n-- > 0) {
            fast = fast.next;
        }
        if (fast == null) {
            return head.next;
        }
        while (fast.next != null) {
            fast = fast.next;
            slow = slow.next;
        }
        slow.next = slow.next.next;
        return head;
    }

    // public ListNode removeNthFromEnd(ListNode head, int n) {
    //     var fake = new ListNode(0, head);
    //     var slow = fake;
    //     var fast = fake;
    //     while (n-- > 0) {
    //         fast = fast.next;
    //     }
    //     while (fast.next != null) {
    //         fast = fast.next;
    //         slow = slow.next;
    //     }
    //     slow.next = slow.next.next;
    //     return fake.next;
    // }

    // private int n;

    // private void remove(ListNode head) {
    //     if (head.next == null) {
    //         return;
    //     }
    //     remove(head.next);
    //     if (--n == 0) {
    //         head.next = head.next.next;
    //     }
    // }

    // public ListNode removeNthFromEnd(ListNode head, int n) {
    //     var fake = new ListNode(0, head);
    //     this.n = n;
    //     this.remove(fake);
    //     return fake.next;
    // }

    public static void main(String[] args) {
        var o = new Solution();

        assertThat(o.removeNthFromEnd(of(1, 2, 3, 4, 5), 2)).isEqualTo(of(1, 2, 3, 5));
        assertThat(o.removeNthFromEnd(of(1), 1)).isNull();
        assertThat(o.removeNthFromEnd(of(1, 2), 1)).isEqualTo(of(1));

        var start = Instant.now();
        for (var i = 0; i < 100; i++) {
            o.removeNthFromEnd(of(1, 2, 3, 4, 5), 2);
            o.removeNthFromEnd(of(1), 1);
            o.removeNthFromEnd(of(1, 2), 1);
        }
        System.out.println(ChronoUnit.MICROS.between(start, Instant.now()));
    }
}
