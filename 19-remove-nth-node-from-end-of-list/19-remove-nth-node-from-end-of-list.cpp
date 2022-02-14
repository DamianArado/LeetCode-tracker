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
        if(head == NULL || head->next == NULL) return NULL;
        ListNode *pNthNode = head, *pTemp = head, *prevTemp = head;
        while(pNthNode && n--) pNthNode = pNthNode->next;
        if(pNthNode == NULL) return head->next;
        while(pNthNode) {
            prevTemp = pTemp;
            pNthNode = pNthNode->next;
            pTemp = pTemp->next;
        }
        prevTemp->next = pTemp->next;
        return head;
    }
};