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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode *prev = NULL, *curr = head, *nxt = head->next;
        while(curr != NULL) {
            curr->next = prev;
            prev = curr;
            curr = nxt;
            if(nxt != NULL) nxt = nxt->next;
        }
        return prev;
    }
};

/*
Recursive approach -> TC O(n) SC O(n)
ListNode* reverseList(ListNode* head) {
        if(head->next` == NULL) return head;
        ListNode* reversedHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
}
ListNode* reverseList(ListNode* head) {
       if(head == NULL) return NULL;
       return reverse(head);
}
*/