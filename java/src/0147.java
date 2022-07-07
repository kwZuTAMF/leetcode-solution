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
    public ListNode insertionSortList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        var fake = new ListNode(0, head);
        var slow = head;
        var fast = head.next;
        while (fast != null) {
            if (slow.val <= fast.val) {
                slow = slow.next;
            } else {
                var prev = fake;
                while (prev.next.val <= fast.val) {
                    prev = prev.next;
                }
                slow.next = fast.next;
                fast.next = prev.next;
                prev.next = fast;
            }
            fast = slow.next;
        }
        return fake.next;
    }

    public static void main(String[] args) {
        var o = new Solution();

        assertThat(o.insertionSortList(of(4, 2, 1, 3))).isEqualTo(of(1, 2, 3, 4));
        assertThat(o.insertionSortList(of(-1, 5, 3, 4, 0))).isEqualTo(of(-1, 0, 3, 4, 5));

        var start = Instant.now();
        for (var i = 0; i < 10000; i++) {
            o.insertionSortList(of(4, 2, 1, 3));
            o.insertionSortList(of(-1, 5, 3, 4, 0));
        }
        System.out.println(ChronoUnit.MICROS.between(start, Instant.now()));
    }
}
