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
// Recursive code -
// class Solution {
//     private ListNode reverseList(ListNode current, ListNode previous) {
//         if(current == null) return previous;
//         ListNode next = current.next;
//         current.next = previous;
//         return reverseList(next, current);
//     }
//     public ListNode reverseList(ListNode head) {
//         return reverseList(head, null);
//     }
// }
class Solution {
    public ListNode reverseList(ListNode head) {
        if(head == null || head.next == null) return head;
        ListNode prev = null, current = head;
        while(current.next != null) {
            ListNode currentNext = current.next;
            current.next = prev;
            prev = current;
            current = currentNext;
        }
        current.next = prev;
        return current;
    }
}