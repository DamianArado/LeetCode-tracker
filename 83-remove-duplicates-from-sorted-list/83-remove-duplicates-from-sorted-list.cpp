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

// Iterative approach - TC -> O(n) SC -> O(1)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // corner cases
        if(head == NULL || head->next == NULL) return head;
        ListNode *temp = head;
        while(temp->next != NULL) {
            if(temp->val == temp->next->val) {
                ListNode *del = temp->next;
                temp->next = del->next;
                delete del;
            } else {
                temp = temp->next;
            }
        }
        return head;
    }
};

/*
// Recursive approach - TC -> O(n) SC -> O(n)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // corner cases
        if(head == NULL || head->next == NULL) return head;
        ListNode *newHead = deleteDuplicates(head->next);
        if(head->val == newHead->val) return newHead;
        else {
            head->next = newHead;
            return head;
        }
    }
};
*/