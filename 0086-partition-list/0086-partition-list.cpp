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
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL or head->next == NULL) 
            return head;
        ListNode node1(-1), node2(-1);
        ListNode *ptr1 = &node1, *ptr2 = &node2, *current = head;
        while (current != NULL) {
            if (current->val < x)
                ptr1 = (ptr1->next = current);
            else
                ptr2 = (ptr2->next = current);
            current = current->next;
        }
        ptr2->next = NULL;
        ptr1->next = node2.next;
        return node1.next;
    }
};