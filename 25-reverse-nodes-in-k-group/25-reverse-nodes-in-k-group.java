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
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode prev = new ListNode(-1, null);
        ListNode current = head;
        for(int i = 0; i < k; ++i) {
            if(current == null) return head;
            current = current.next;
        }
        current = head;
        for(int i = 0; i < k; ++i) {
            ListNode next = current.next;
            current.next = prev;
            prev = current;
            current = next;
        }
        head.next = reverseKGroup(current, k);
        return prev;
    }
}