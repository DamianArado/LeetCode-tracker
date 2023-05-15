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
    public ListNode swapNodes(ListNode head, int k) {
        ListNode left = head, right = head, current = head;
        int cnt = 1;
        while(current != null) {
            if(cnt < k) left = left.next;
            if(cnt > k) right = right.next;
            ++cnt;
            current = current.next;
        }
        int val = left.val;
        left.val = right.val;
        right.val = val;
        return head;
    }
}