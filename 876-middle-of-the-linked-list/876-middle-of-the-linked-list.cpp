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
    ListNode* middleNode(ListNode* head) {
        int sizeLL = 0;
        ListNode* temp = head;
        while(temp != NULL) {
            sizeLL++;
            temp = temp->next;
        }
        sizeLL /= 2;
        temp = head;
        while(sizeLL--) temp = temp->next;
        return temp;
    }
};