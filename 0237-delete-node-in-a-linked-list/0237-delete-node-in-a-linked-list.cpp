/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        // since its not the tail node we are 100% sure there is atleast one node after this 
        // lets swap the node with its next node
        swap(node->val, node->next->val);
        // mark this to be deleted
        ListNode* temp = node->next;
        // change the connections
        node->next = temp->next;
        // now delete this node
        delete temp;
    }
};