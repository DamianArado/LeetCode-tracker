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

// Iterative solution
// TC -> O(n)
// SC -> O(1)
class Solution {
public:
    void reverse(ListNode *start, ListNode *end) {
        ListNode *prev = NULL, *curr = start, *nxt = start->next;   
        while(prev != end) {
            curr->next = prev;
            prev = curr;
            curr = nxt;
            if(nxt != NULL) nxt = nxt->next;
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Corner cases
        if(head == NULL || head->next == NULL || k == 1) return head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *beforeStart = dummy, *end = head;
        int i = 0;
        while(end != NULL) {
            i++;
            if(i % k == 0) {
                ListNode *start = beforeStart->next, *temp = end->next;
                reverse(start, end);
                beforeStart->next = end;
                start->next = temp;
                beforeStart = start;
                end = temp;
            } else {
                end = end->next;
            }
        }
        return dummy->next;
    }
};



/*
// Recursive solution
// TC -> O(n)
// SC -> O(n/k) for recursion stack size
class Solution {
public:
    void reverse(ListNode *start, ListNode *end) {
        ListNode *prev = NULL, *curr = start, *nxt = start->next;   
        while(prev != end) {
            curr->next = prev;
            prev = curr;
            curr = nxt;
            if(nxt != NULL) nxt = nxt->next;
        }
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Corner cases
        if(head == NULL || head->next == NULL || k == 1) return head;
        ListNode *start = head, *end = head;
        int incr = k - 1;
        while(incr--) {
            end = end->next;
            if(end == NULL) return head;
        }
        ListNode *nextHead = reverseKGroup(end->next, k);
        reverse(start, end);
        start->next = nextHead;
        return end;
    }
};
*/