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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *mickey = new ListNode(-1, NULL);
        ListNode *head1 = l1, *head2 = l2, *dummy = mickey;
        
        while(head1 and head2) {
            int num1 = head1->val, num2 = head2->val;
            int sum = num1 + num2, carry = 0;
            if(sum > 9) {
                carry = 1;
                sum %= 10;
            }
            ListNode *newNode = new ListNode(sum, NULL);
            if(carry > 0) {
                if(head1->next) head1->next->val += 1;
                else if(head2->next) head2->next->val += 1;
                else {
                    newNode->next = new ListNode(1, NULL);
                }
            }
            dummy->next = newNode;
            dummy = newNode;
            head1 = head1->next, head2 = head2->next;
        }
        
        while(head1) {
            if(head1->val <= 9) {
                dummy->next = new ListNode(head1->val, NULL);
                dummy = dummy->next;
                head1 = head1->next;
            } else {
                int val = (head1->val) % 10, carry = 1;
                dummy->next = new ListNode(val, NULL);
                dummy = dummy->next;
                if(head1->next) head1->next->val += 1;
                else dummy->next = new ListNode(1, NULL);
                head1 = head1->next;
            }
        }
        
        while(head2) {
            if(head2->val <= 9) {
                dummy->next = new ListNode(head2->val, NULL);
                dummy = dummy->next;
                head2 = head2->next;
            } else {
                int val = (head2->val) % 10, carry = 1;
                dummy->next = new ListNode(val, NULL);
                dummy = dummy->next;
                if(head2->next) head2->next->val += 1;
                else dummy->next = new ListNode(1, NULL);
                head2 = head2->next;
            }
        }
        
        return mickey->next;
    }
};