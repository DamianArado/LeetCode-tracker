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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        ListNode *dummy = new ListNode(-1, head);
        auto sublistHead = dummy;
        int k = 1;
        while(k++ < left) sublistHead = sublistHead->next;
        auto sublistItr = sublistHead->next;
        while(left++ < right) {
            auto temp = sublistItr->next;
            sublistItr->next = temp->next;
            temp->next = sublistHead->next;
            sublistHead->next = temp;
        }
        return dummy->next;
    }
};