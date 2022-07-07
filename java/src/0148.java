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
    public ListNode sortList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        var size = 0;
        var tail = head;
        while (tail != null) {
            tail = tail.next;
            size++;
        }
        var fake = new ListNode(0, head);
        for (var step = 1; step < size; step <<= 1) {
            var prev = fake;
            var curr = fake.next;
            while (curr != null) {
                var i = step;
                var p = curr;
                for (; curr != null && i > 0; i--) {
                    curr = curr.next;
                }
                if (i > 0) {
                    break;
                }
                var j = step;
                var q = curr;
                for (; curr != null && j > 0; j--) {
                    curr = curr.next;
                }
                var m = step;
                var n = step - j;
                while (m > 0 && n > 0) {
                    if (p.val <= q.val) {
                        prev.next = p;
                        p = p.next;
                        m--;
                    } else {
                        prev.next = q;
                        q = q.next;
                        n--;
                    }
                    prev = prev.next;
                }
                prev.next = m > 0 ? p : q;
                for (; m > 0 || n > 0; m--, n--) {
                    prev = prev.next;
                }
                prev.next = curr;
            }
        }
        return fake.next;
    }

    // public ListNode sortList(ListNode head) {
    //     if (head == null || head.next == null) {
    //         return head;
    //     }
    //     var prev = head;
    //     var slow = head;
    //     var fast = head;
    //     while (fast != null && fast.next != null) {
    //         prev = slow;
    //         slow = slow.next;
    //         fast = fast.next.next;
    //     }
    //     prev.next = null;
    //     var lst1 = sortList(head);
    //     var lst2 = sortList(slow);
    //     var fake = new ListNode();
    //     var curr = fake;
    //     while (lst1 != null && lst2 != null) {
    //         if (lst1.val <= lst2.val) {
    //             curr.next = lst1;
    //             lst1 = lst1.next;
    //         } else {
    //             curr.next = lst2;
    //             lst2 = lst2.next;
    //         }
    //         curr = curr.next;
    //     }
    //     curr.next = lst1 != null ? lst1 : lst2;
    //     return fake.next;
    // }

    public static void main(String[] args) {
        var o = new Solution();

        assertThat(o.sortList(of(-1, 5, 3, 4, 0))).isEqualTo(of(-1, 0, 3, 4, 5));
        assertThat(o.sortList(null)).isNull();
        assertThat(o.sortList(of(5, 4, 3, 2, 1))).isEqualTo(of(1, 2, 3, 4, 5));

        var start = Instant.now();
        for (var i = 0; i < 10000; i++) {
            o.sortList(of(-1, 5, 3, 4, 0));
            o.sortList(null);
        }
        System.out.println(ChronoUnit.MICROS.between(start, Instant.now()));
    }
}
