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
    int getDecimalValue(ListNode* head) {
        ListNode *temp = head;
        int ans = 0;
        // assume we are at the last node
        while(temp != NULL) {
            // for every node we leave behind, multiply 2 to the answer
            ans *= 2;
            // we add the current value of the node
            ans += temp->val;
            temp = temp->next;
        }
        return ans;
    }
};