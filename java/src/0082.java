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
    // public ListNode deleteDuplicates(ListNode head) {
    //     if (head == null || head.next == null) {
    //         return head;
    //     }
    //     var fake = new ListNode(0x7fffffff, head);
    //     var curr = fake;
    //     while (curr.next != null && curr.next.next != null) {
    //         if (curr.next.val != curr.next.next.val) {
    //             curr = curr.next;
    //         } else {
    //             var val = curr.next.val;
    //             while (curr.next != null && curr.next.val == val) {
    //                 curr.next = curr.next.next;
    //             }
    //         }
    //     }
    //     return fake.next;
    // }

    public ListNode deleteDuplicates(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        var fake = new ListNode(0, head);
        var slow = fake;
        var fast = head;
        while (fast != null) {
            while (fast.next != null && fast.val == fast.next.val) {
                fast = fast.next;
            }
            if (slow.next != fast) {
                slow.next = fast.next;
            } else {
                slow = slow.next;
            }
            fast = fast.next;
        }
        return fake.next;
    }

    public static void main(String[] args) {
        var o = new Solution();

        assertThat(o.deleteDuplicates(of(1, 2, 3, 3, 4, 4, 5))).isEqualTo(of(1, 2, 5));
        assertThat(o.deleteDuplicates(of(1, 1, 1, 2, 3))).isEqualTo(of(2, 3));

        var start = Instant.now();
        for (var i = 0; i < 10000; i++) {
            o.deleteDuplicates(of(1, 2, 3, 3, 4, 4, 5));
            o.deleteDuplicates(of(1, 1, 1, 2, 3));
        }
        System.out.println(ChronoUnit.MICROS.between(start, Instant.now()));
    }
}
