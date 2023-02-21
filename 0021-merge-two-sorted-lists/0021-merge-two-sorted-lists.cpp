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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        ListNode *dummy = new ListNode(-1, NULL);
        ListNode *current = dummy;
        while(list1 != NULL and list2 != NULL) {
            if(list1->val <= list2->val) {
                current->next = list1;
                current = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                current = list2;
                list2 = list2->next;
            }
        }
        if(list1 != NULL) current->next = list1;
        if(list2 != NULL) current->next = list2;
        return dummy->next;
    }
};