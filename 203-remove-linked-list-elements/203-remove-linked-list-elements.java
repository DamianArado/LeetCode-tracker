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
    public ListNode removeElements(ListNode head, int val) {
        if(head == null) return null;
        
        ListNode current = head;
        ListNode prev = new ListNode(-1, current);
        ListNode ans = prev;
        
        while(current != null) {
            if(current.val == val)
                prev.next = current.next;
            else 
                prev = current;
            current = current.next;
        }
        
        return ans.next;
    }
}