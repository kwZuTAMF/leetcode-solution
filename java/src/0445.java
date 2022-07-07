import static org.assertj.core.api.Assertions.assertThat;
import static structs.util.LinkedList.of;

import java.time.Instant;
import java.time.temporal.ChronoUnit;
import java.util.LinkedList;

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
        var s1 = new LinkedList<Integer>();
        var s2 = new LinkedList<Integer>();
        for (var p = l1; p != null; p = p.next) {
            s1.push(p.val);
        }
        for (var q = l2; q != null; q = q.next) {
            s2.push(q.val);
        }
        var carry = 0;
        ListNode prev = null;
        while (!s1.isEmpty() || !s2.isEmpty() || carry != 0) {
            if (!s1.isEmpty()) {
                carry += s1.pop();
            }
            if (!s2.isEmpty()) {
                carry += s2.pop();
            }
            var curr = new ListNode(carry % 10, prev);
            carry /= 10;
            prev = curr;
        }
        return prev;
    }

    public static void main(String[] args) {
        var o = new Solution();

        assertThat(o.addTwoNumbers(of(7, 2, 4, 3), of(5, 6, 4)))
                .isEqualTo(of(7, 8, 0, 7));
        assertThat(o.addTwoNumbers(of(2, 4, 3), of(5, 6, 4)))
                .isEqualTo(of(8, 0, 7));
        assertThat(o.addTwoNumbers(of(0), of(0))).isEqualTo(of(0));

        var start = Instant.now();
        for (var i = 0; i < 1000000; i++) {
            o.addTwoNumbers(of(7, 2, 4, 3), of(5, 6, 4));
            o.addTwoNumbers(of(2, 4, 3), of(5, 6, 4));
            o.addTwoNumbers(of(0), of(0));
        }
        System.out.println(ChronoUnit.MICROS.between(start, Instant.now()));
    }
}
