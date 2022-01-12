// [leetcode 0083] Remove Duplicates from Sorted List

public class ListNode
{
    int val;
    ListNode next;

    ListNode()
    {}

    ListNode(int val)
    {
        this.val = val;
    }

    ListNode(int val, ListNode next)
    {
        this.val = val;
        this.next = next;
    }
}

class Solution
{
    public ListNode deleteDuplicates(ListNode head)
    {
        if (head == null)
        {
            return head;
        }

        ListNode pivot = head;
        int pivotVal = 0;
        while (pivot.next != null)
        {
            pivotVal = pivot.val;
            if (pivotVal == pivot.next.val)
            {
                pivot.next = pivot.next.next;
            }
            else
            {
                pivot = pivot.next;
            }
        }

        return head;
    }
}
