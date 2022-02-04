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
// Recursive approach - TC -> O(n) SC -> O(n)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // corner cases
        if(head == NULL || head->next == NULL) return head;
        ListNode* dummy = new ListNode(-101);
        ListNode *tail = dummy;
        while(head != NULL) {
            if(head->next && head->val == head->next->val) {
                int curr = head->val;
                // skip all values that are the same
                while(head && curr == head->val) head = head->next;
            } else {
                // add elements which are single to the tail
                tail->next = head;
                tail = head;
                head = head->next;
            }
            tail->next = NULL;
        }
        return dummy->next;
    }
};