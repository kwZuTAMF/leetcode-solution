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
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null || head.next == null || k == 0) {
            return head;
        }
        ListNode curr = head;
        int size = 1;
        while (curr.next != null) {
            curr = curr.next;
            size++;
        }
        int step = size - k % size;
        if (step == size) {
            return head;
        }
        curr.next = head;
        while (step-- > 0) {
            curr = curr.next;
        }
        head = curr.next;
        curr.next = null;
        return head;
    }

    public static void main(String[] args) {
        var o = new Solution();

        assertThat(o.rotateRight(of(1, 2, 3, 4, 5), 2)).isEqualTo(of(4, 5, 1, 2, 3));
        assertThat(o.rotateRight(of(0, 1, 2), 4)).isEqualTo(of(2, 0, 1));

        var start = Instant.now();
        for (var i = 0; i < 10000; i++) {
            o.rotateRight(of(1, 2, 3, 4, 5), 2);
            o.rotateRight(of(0, 1, 2), 4);
        }
        System.out.println(ChronoUnit.MICROS.between(start, Instant.now()));
    }
}
