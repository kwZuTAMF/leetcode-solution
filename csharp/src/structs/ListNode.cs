namespace Structs;

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class ListNode {
    public int val { get; }
    public ListNode next { get; set; }

    public ListNode(int val = 0, ListNode next = null) {
        this.val = val;
        this.next = next;
    }

    public override int GetHashCode() {
        return base.GetHashCode();
    }

    public override bool Equals(object obj) {
        return obj != null && ToString() == obj.ToString();
    }

    public override string ToString() {
        return next == null ? $"{val}" : $"{val}->{next}";
    }

    public static ListNode of(params int[] items) {
        var head = new ListNode();
        var curr = head;
        foreach (var item in items) {
            curr.next = new ListNode(item);
            curr = curr.next;
        }
        return head.next;
    }
}
