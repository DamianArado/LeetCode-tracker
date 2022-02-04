/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// TC -> O(n)  SC -> O(1) using slow and fast pointers
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }
        return false;
    }
};

/*
Approach 1 will use set to store the nodes. Whenever we try to store a node again, we 
can check if its already present or not. 

TC -> O(n)  SC -> T(n)
*/

