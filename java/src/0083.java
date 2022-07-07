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
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        var curr = head;
        while (curr.next != null) {
            if (curr.val == curr.next.val) {
                curr.next = curr.next.next;
            } else {
                curr = curr.next;
            }
        }
        return head;
    }

    public static void main(String[] args) {
        var o = new Solution();

        assertThat(o.deleteDuplicates(of(1, 1, 2))).isEqualTo(of(1, 2));
        assertThat(o.deleteDuplicates(of(1, 1, 2, 3, 3))).isEqualTo(of(1, 2, 3));

        var start = Instant.now();
        for (var i = 0; i < 10000; i++) {
            o.deleteDuplicates(of(1, 1, 2));
            o.deleteDuplicates(of(1, 1, 2, 3, 3));
        }
        System.out.println(ChronoUnit.MICROS.between(start, Instant.now()));
    }

}
