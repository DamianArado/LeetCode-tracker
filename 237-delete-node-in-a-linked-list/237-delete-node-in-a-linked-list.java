/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public void deleteNode(ListNode node) {
        ListNode temp = node;
        node.val = node.next.val;
        node.next.val = temp.val;
        ListNode temp2 = node.next;
        node.next = node.next.next;
        temp2 = null; 
        temp = null;
    }
}