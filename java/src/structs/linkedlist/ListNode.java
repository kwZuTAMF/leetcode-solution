package structs.linkedlist;

public class ListNode {
    public int val;
    public ListNode next;

    public ListNode() {
    }

    public ListNode(int val) {
        this.val = val;
    }

    public ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }

    @Override
    public int hashCode() {
        return 31 * val + (next == null ? 0 : next.hashCode());
    }

    @Override
    public boolean equals(Object o) {
        if (this == o)
            return true;
        if (o == null || getClass() != o.getClass())
            return false;
        return toString().equals(o.toString());
    }

    @Override
    public String toString() {
        return next == null ? Integer.toString(val) : val + "->" + next;
    }
}
