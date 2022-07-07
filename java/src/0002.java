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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        var fake = new ListNode();
        var curr = fake;
        var carry = 0;
        while (l1 != null || l2 != null || carry == 1) {
            if (l1 != null) {
                carry += l1.val;
                l1 = l1.next;
            }
            if (l2 != null) {
                carry += l2.val;
                l2 = l2.next;
            }
            curr.next = new ListNode(carry % 10);
            curr = curr.next;
            carry /= 10;
        }
        return fake.next;
    }

    public static void main(String[] args) {
        var o = new Solution();

        assertThat(o.addTwoNumbers(of(2, 4, 3), of(5, 6, 4))).isEqualTo((of(7, 0, 8)));
        assertThat(o.addTwoNumbers(of(0), of(0))).isEqualTo((of(0)));
        assertThat(o.addTwoNumbers(of(9, 9, 9, 9, 9, 9, 9), of(9, 9, 9, 9))).isEqualTo((of(8, 9, 9, 9, 0, 0, 0, 1)));

        var start = Instant.now();
        for (var i = 0; i < 1000000; i++) {
            o.addTwoNumbers(of(2, 4, 3), of(5, 6, 4));
            o.addTwoNumbers(of(0), of(0));
            o.addTwoNumbers(of(9, 9, 9, 9, 9, 9, 9), of(9, 9, 9, 9));
        }
        System.out.println(ChronoUnit.MICROS.between(start, Instant.now()));
    }
}
