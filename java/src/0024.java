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
    public ListNode swapPairs(ListNode head) {
        var fake = new ListNode(0, head);
        var curr = fake;
        while (curr.next != null && curr.next.next != null) {
            var next = curr.next;
            var temp = next.next.next;
            curr.next = next.next;
            next.next.next = next;
            next.next = temp;
            curr = next;
        }
        return fake.next;
    }

    public static void main(String[] args) {
        var o = new Solution();

        assertThat(o.swapPairs(of(1, 2, 3, 4))).isEqualTo(of(2, 1, 4, 3));
        assertThat(o.swapPairs(null)).isNull();
        assertThat(o.swapPairs(of(1))).isEqualTo(of(1));

        var start = Instant.now();
        for (var i = 0; i < 100; i++) {
            o.swapPairs(of(1, 2, 3, 4, 5));
            o.swapPairs(of(1));
            o.swapPairs(of(1, 2));
        }
        System.out.println(ChronoUnit.MICROS.between(start, Instant.now()));
    }
}
