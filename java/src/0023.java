import static org.assertj.core.api.Assertions.assertThat;
import static structs.util.LinkedList.of;

import java.time.Instant;
import java.time.temporal.ChronoUnit;
import java.util.PriorityQueue;

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
    public ListNode mergeKLists(ListNode[] lists) {
        var k = lists.length;
        if (k == 0) {
            return null;
        }
        for (var step = 1; step < k; step <<= 1) {
            for (var i = 0; i + step < k; i += step << 1) {
                var lst1 = lists[i];
                var lst2 = lists[i + step];
                var fake = new ListNode();
                var curr = fake;
                while (lst1 != null && lst2 != null) {
                    if (lst1.val <= lst2.val) {
                        curr.next = lst1;
                        lst1 = lst1.next;
                    } else {
                        curr.next = lst2;
                        lst2 = lst2.next;
                    }
                    curr = curr.next;
                }
                curr.next = lst1 != null ? lst1 : lst2;
                lists[i] = fake.next;
            }
        }
        return lists[0];
    }

    // public ListNode mergeKLists(ListNode[] lists) {
    //     switch (lists.length) {
    //         case 0:
    //             return null;
    //         case 1:
    //             return lists[0];
    //         default:
    //             return merge(lists, 0, lists.length - 1);
    //     }
    // }

    // private ListNode merge(ListNode[] lists, int left, int right) {
    //     if (left == right) {
    //         return lists[left];
    //     }
    //     var mid = (left + right) >>> 1;
    //     var lst1 = merge(lists, left, mid);
    //     var lst2 = merge(lists, mid + 1, right);
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

    // public ListNode mergeKLists(ListNode[] lists) {
    //     var k = lists.length;
    //     switch (k) {
    //         case 0:
    //             return null;
    //         case 1:
    //             return lists[0];
    //         default: {
    //             var fake = new ListNode();
    //             var curr = fake;
    //             var heap = new PriorityQueue<ListNode>(k, (a, b) -> a.val - b.val);
    //             for (var list : lists) {
    //                 if (list != null) {
    //                     heap.offer(list);
    //                 }
    //             }
    //             while (!heap.isEmpty()) {
    //                 curr.next = heap.poll();
    //                 curr = curr.next;
    //                 if (curr.next != null) {
    //                     heap.offer(curr.next);
    //                 }
    //             }
    //             return fake.next;
    //         }
    //     }
    // }

    public static void main(String[] args) {
        var o = new Solution();

        assertThat(o.mergeKLists(new ListNode[] { of(3, 3, 3), null, of(3, 3, 3) }))
                .isEqualTo(of(3, 3, 3, 3, 3, 3));
        assertThat(o.mergeKLists(new ListNode[] { of(1, 4, 5), of(1, 3, 4), of(2, 6) }))
                .isEqualTo(of(1, 1, 2, 3, 4, 4, 5, 6));
        assertThat(o.mergeKLists(new ListNode[] {})).isNull();
        assertThat(o.mergeKLists(new ListNode[] { null })).isNull();

        var start = Instant.now();
        for (var i = 0; i < 1000000; i++) {
            o.mergeKLists(new ListNode[] { of(3, 3, 3), of(3, 3, 3) });
            o.mergeKLists(new ListNode[] { of(1, 4, 5), of(1, 3, 4), of(2, 6) });
            o.mergeKLists(new ListNode[] {});
            o.mergeKLists(new ListNode[] { null });
        }
        System.out.println(ChronoUnit.MICROS.between(start, Instant.now()));
    }
}
