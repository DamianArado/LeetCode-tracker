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
    ListNode* swapNodes(ListNode* head, int k) {
        int length = 0;
        ListNode *current = head;
        while(current != NULL) {
            current = current->next;
            ++length;
        }
        ListNode *first = head, *second = head;
        current = head;
        int temp = 1;
        while(temp < k) {
            current = current->next;
            ++temp;
        }
        first = current, k = length - k + 1, temp = 1, current = head;
        while(temp < k) {
            current = current->next;
            ++temp;
        }
        second = current;
        swap(first->val, second->val);
        return head;
    }
};