import static org.assertj.core.api.Assertions.assertThat;
import static structs.util.LinkedList.of;

import java.time.Instant;
import java.time.temporal.ChronoUnit;

import structs.linkedlist.ListNode;

class Solution {

    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        var fake = new ListNode();
        var curr = fake;
        while (list1 != null && list2 != null) {
            if (list1.val <= list2.val) {
                curr.next = list1;
                list1 = list1.next;
            } else {
                curr.next = list2;
                list2 = list2.next;
            }
            curr = curr.next;
        }
        curr.next = list1 != null ? list1 : list2;
        return fake.next;
    }

    public static void main(String[] args) {
        record Case(ListNode list1, ListNode list2, ListNode excepted) {
        }

        var CASES = new Case[] {
                new Case(of(1, 2, 4), of(1, 3, 4), of(1, 1, 2, 3, 4, 4)),
                new Case(null, null, null),
                new Case(null, of(0), of(0)),
        };

        var o = new Solution();

        for (var x : CASES) {
            assertThat(o.mergeTwoLists(x.list1, x.list2)).isEqualTo(x.excepted);
        }

        var start = Instant.now();
        for (var i = 0; i < 1000000; i++) {
            o.mergeTwoLists(of(1, 2, 4), of(1, 3, 4));
            o.mergeTwoLists(null, null);
            o.mergeTwoLists(null, of(0));
        }
        System.out.println(ChronoUnit.MICROS.between(start, Instant.now()));
    }

}
