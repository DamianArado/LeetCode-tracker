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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || head->next == NULL) return NULL;  // base-case
        ListNode *pNthNode = head, *pTemp = head, *prevTemp = head;  // we'll use 3 pointers
        while(pNthNode && n--) pNthNode = pNthNode->next;  // at max n = length of list
        if(pNthNode == NULL) return head->next;  // in that case we can just return this
        while(pNthNode) {  // otherwise move step-by-step till pNthNode = NULL and delete pTemp
            prevTemp = pTemp;
            pNthNode = pNthNode->next; 
            pTemp = pTemp->next;
        }
        prevTemp->next = pTemp->next;
        delete pTemp;
        return head;
    }
};