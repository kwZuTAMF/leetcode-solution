using System;
using System.Diagnostics;

using Structs;

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode GetIntersectionNode(ListNode headA, ListNode headB) {
        if (headA == null || headB == null) {
            return null;
        }
        var p = headA;
        var q = headB;
        while (p != q) {
            p = p?.next ?? headB;
            q = q?.next ?? headA;
        }
        return headA;
    }
}
