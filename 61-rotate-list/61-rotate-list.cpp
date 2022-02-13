/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 || head == NULL || head->next == NULL) return head;  // base-cases
        ListNode *end = head, *prev = head;
        int len = 1;  // to store the size of list
        while(end->next) {
            end = end->next;  // reach the last node
            len++;
        }
        if(k % len == 0) return head; // optimization
        
        // will need to move ahead by k steps (head)
        if(k < len) k = len - k;
        else k = len - k % len;
        
        if(k) end->next = head;   // connect the end to current head
        while(k--) {
            prev = head;
            head = head->next;
        }
        if(k && prev != head) prev->next = NULL;  // prev becomes the last node of our rotated list
        return head;  // new head
    }
};