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
    public ListNode reverseKGroup(ListNode head, int k) {
        var fake = new ListNode(0, head);
        var prev = fake;
        var slow = head;
        var fast = head;
        while (fast != null) {
            var step = -1;
            while (++step < k && fast != null) {
                fast = fast.next;
            }
            if (step == k) {
                head = reverse(slow, fast);
                prev.next = head;
                prev = slow;
                slow = fast;
            }
        }
        return fake.next;
    }

    private ListNode reverse(ListNode head, ListNode tail) {
        var prev = tail;
        var curr = head;
        while (curr != tail) {
            var next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    public static void main(String[] args) {
        var o = new Solution();

        assertThat(o.reverseKGroup(of(1, 2, 3, 4, 5), 2)).isEqualTo(of(2, 1, 4, 3, 5));
        assertThat(o.reverseKGroup(of(1, 2, 3, 4, 5), 3)).isEqualTo(of(3, 2, 1, 4, 5));

        var start = Instant.now();
        for (var i = 0; i < 10000; i++) {
            o.reverseKGroup(of(1, 2, 3, 4, 5), 2);
            o.reverseKGroup(of(1, 2, 3, 4, 5), 3);
        }
        System.out.println(ChronoUnit.MICROS.between(start, Instant.now()));
    }
}
