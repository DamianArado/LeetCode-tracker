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
    bool isPalindrome(ListNode* head) {
        if (head == NULL or head->next == NULL) 
            return true;
        // reverse the one half and check using 2 pointers if both halves are same or not
        int n = 0;
        ListNode *current = head;
        while (current != NULL) { 
            current = current->next; 
            ++n; 
        }
        ListNode *slow = head, *fast = head;
        while (fast != NULL and fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        current = head;
        ListNode* prev = new ListNode(-1);
        while (current != slow) {
            ListNode *currNext = current->next;
            current->next = prev;
            prev = current;
            current = currNext;
        }
        head = prev;
        if (n % 2 == 1) 
            current = current->next;
        while (current != NULL and head->val != -1) {
            if (current->val != head->val) 
                return false;
            current = current->next;
            head = head->next;
        }
        return true;
    }
};