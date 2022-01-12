// [leetcode 0141] Linked List Cycle

class Solution
{
    public boolean hasCycle(ListNode head)
    {
        ListNode walker = head;
        ListNode runner = head;

        while (runner != null)
        {
            runner = runner.next;

            if (runner == null)
            {
                return false;
            }

            if (runner == walker)
            {
                return true;
            }

            runner = runner.next;
            walker = walker.next;
        }

        return false;
    }
}
