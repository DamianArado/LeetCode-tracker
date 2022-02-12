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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return NULL; // base-case
        ListNode *dummy = new ListNode(-1, head);
        ListNode *tail = dummy;
        while(tail && tail->next) {
            if(tail->next->val == val) {
                ListNode *temp = tail->next;
                tail->next = temp->next;
                delete temp;
            } else tail = tail->next;
        }
        return dummy->next;
    }
};

// Recursive implementation : O(n) time and space
/*
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return NULL; // base-case
        head->next = removeElements(head->next, val);
        if(head->val == val) {
            ListNode *ans = head->next;
            delete head;
            return ans;
        } else {
            return head;
        }
    }
*/