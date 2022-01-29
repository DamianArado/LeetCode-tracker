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
        ListNode* prev=NULL, *temp=head;
        if(head == NULL) return head; // if the linked list is empty
        while(temp) {
            if(temp->val == val) {
                if(temp == head) { // if the node to be removed is at the beginning of the linked list
                    head = temp->next;
                    temp = temp->next;
                }
                else if(temp->next == NULL) { // if the node to be removed is at the end of the linked list
                    prev->next = NULL;
                    temp = temp->next;
                }
                else { // if the node lies somewhere in between
                    temp = temp->next;
                    prev->next = temp;
                }
            } else { // if this is not the target node
                prev = temp;
                temp = temp->next; 
            }  
        }
        delete temp;
        return head;
    }
};