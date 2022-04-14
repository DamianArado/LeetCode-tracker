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
    ListNode* mergeNodes(ListNode* head) {
    for (auto *p_1 = head, *p_2 = head->next; p_2 != nullptr; p_2 = p_2->next) {
        if (p_2->val != 0)
            p_1->val += p_2->val;
        else {
            p_1->next = p_2->next != nullptr ? p_2 : nullptr;
            p_1 = p_2;
        }
    }
    return head;
}
};