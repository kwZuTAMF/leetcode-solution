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
    public ListNode reverseList(ListNode head) {
        ListNode prev = null, next;
        while (head != null) {
            next = head.next;
            head.next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

    public static void main(String[] args) {
        var o = new Solution();

        assertThat(o.reverseList(of(1, 2))).isEqualTo(of(2, 1));
        assertThat(o.reverseList(of(1, 2, 3, 4, 5))).isEqualTo(of(5, 4, 3, 2, 1));
        assertThat(o.reverseList(null)).isNull();

        var start = Instant.now();
        for (var i = 0; i < 1000000; i++) {
            o.reverseList(of(1, 2));
            o.reverseList(of(1, 2, 3, 4, 5));
            o.reverseList(null);
        }
        System.out.println(ChronoUnit.MICROS.between(start, Instant.now()));
    }
}
