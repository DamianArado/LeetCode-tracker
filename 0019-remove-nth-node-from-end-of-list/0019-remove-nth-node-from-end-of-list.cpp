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
        ListNode *fast = head, *slow = head;
        while(n--) fast = fast->next;  // maintaining a gap of n b/w slow & fast pointers
        if(fast == NULL) return head->next;
        while(fast->next != NULL) 
            fast = fast->next, slow = slow->next;
        slow->next = slow->next->next;
        return head;
    }
};