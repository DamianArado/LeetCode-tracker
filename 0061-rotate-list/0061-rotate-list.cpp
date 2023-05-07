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
        if(head == NULL or head->next == NULL) return head;
        int length = 1;
        ListNode *current = head;
        while(current->next != NULL) {
            ++length;
            current = current->next;
        }
        if(k == length) return head;
        if(k > length) k = k % length;
        k = length - k;
        int i = 0;
        current->next = head;
        int cnt = k - 1;
        current = head;
        while(cnt--) 
            current = current->next;
        head = current->next;
        current->next = NULL;
        return head;
    }
};