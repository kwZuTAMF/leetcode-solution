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
    public ListNode removeElements(ListNode head, int val) {
        var fake = new ListNode(0, head);
        var curr = fake;
        while (curr.next != null) {
            if (curr.next.val == val) {
                curr.next = curr.next.next;
            } else {
                curr = curr.next;
            }
        }
        return fake.next;
    }

    public static void main(String[] args) {
        var o = new Solution();

        assertThat(o.removeElements(of(1, 2, 6, 3, 4, 5, 6), 6)).isEqualTo(of(1, 2, 3, 4, 5));
        assertThat(o.removeElements(null, 1)).isNull();
        assertThat(o.removeElements(of(7, 7, 7, 7), 7)).isNull();

        var start = Instant.now();
        for (var i = 0; i < 100; i++) {
            o.removeElements(of(1, 2, 6, 3, 4, 5, 6), 6);
            o.removeElements(null, 1);
            o.removeElements(of(7, 7, 7, 7), 6);
        }
        System.out.println(ChronoUnit.MICROS.between(start, Instant.now()));
    }
}
