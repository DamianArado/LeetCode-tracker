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
    public ListNode rotateRight(ListNode head, int k) {
        if(k == 0 || head == null || head.next == null) return head;
        int len = 1;
        ListNode end = head, prev = head;
        while(end.next != null) {
            end = end.next;
            ++len;
        }
        if(k % len == 0) return head;
        if(k < len) k = len - k;
        else k = len - (k % len);
        end.next = head;
        while(k-- > 0) {
            prev = head;
            head = head.next;
        }
        prev.next = null;
        return head;
    }
}