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
        if(k == 0 || head == NULL || head->next == NULL) return head;  // base-case
        ListNode *temp = head, *end = head, *prev = head;
        int len = 0;  // to store the size of list
        while(end->next) end = end->next;  // reach the last node
        while(temp) {
            temp = temp->next;
            len++;
        }
        int pos = 0;  // will need to move ahead by pos
        
        if(k < len) {
            pos = len - k;
        } else if(k == len) {
            pos = 0;
        } else {
            pos = len - k % len;
        }
        
        if(pos != 0) end->next = head;   // connect the end to current head
        while(pos--) {
            prev = head;
            head = head->next;
        }
        if(pos != 0 && prev != head) prev->next = NULL;  // prev becomes the last node of our rotated list
        return head;  // new head
    }
};