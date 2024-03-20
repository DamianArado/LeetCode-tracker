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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *left = list1;
        int i = 0;
        while (i < a - 1) {
            left = left->next;
            ++i;
        }
        ListNode *right = left;
        while (i < b) {
            right = right->next;
            ++i;
        }
        ListNode *tail2 = list2;
        while (tail2->next != NULL)
            tail2 = tail2->next;
        // here you change the connections
        left->next = list2;
        tail2->next = right->next;
        right->next = NULL;
        return list1;
    }
};