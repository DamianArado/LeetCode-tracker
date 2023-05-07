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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* current = head;
        // check if we need to reverse the groups
        for(int i = 0; i < k; ++i) {
            if(current == NULL) return head;
            current = current->next;
        }
        // reverse the nodes in k-group
        current = head;
        ListNode *prev = NULL;
        for(int i = 0; i < k; ++i) {
            ListNode* nextCurr = current->next;
            current->next = prev;
            prev = current;
            current = nextCurr;
        }
        // after reversing head is the new tail
        head->next = reverseKGroup(current, k);
        return prev;
    }
};