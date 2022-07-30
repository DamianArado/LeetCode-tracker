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
/**

Approach 1- Recursion: O(n) TC & SC

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return nullptr;
        head->next = removeElements(head->next, val);
        if(head->val == val) {
            ListNode *ans = head->next;
            delete head;
            return ans;
        }
        return head;
    }
};

Approach 2- Iterative O(n) TC & O(1) SC

*/
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return nullptr;
        ListNode* current = head;
        ListNode *prev = new ListNode(-1, current);
        ListNode *ans = prev;
        while(current) {
            if(current->val == val)
                prev->next = current->next;
            else 
                prev = current;
            current = current->next;
        }
        return ans->next;
    }
};