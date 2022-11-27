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
// class Solution {
// public:
//     ListNode* removeNodes(ListNode* head) {
//         if(!head or !head->next) return head;
//         ListNode* nextNode = removeNodes(head->next);
//         if(nextNode->val > head->val) return nextNode;
//         head->next = nextNode;
//         return head;
//     }
// };

// Much better solution - O(n) time and O(1) space
// We reverse the list, and "eat" next elements if value is smaller. Then, we reverve the list again.
class Solution {
private:
    ListNode* reverse(ListNode *current, ListNode *previous) {
        while(current->next) {
            ListNode* nxt = current->next;
            current->next = previous;
            previous = current;
            current = nxt;
        }
        current->next = previous;
        return current;
    }
public:
    ListNode* removeNodes(ListNode* head) {
        head = reverse(head, NULL);
        ListNode *current = head;
        while(current->next) {
            ListNode *nextNode = current->next;
            if(nextNode->val < current->val) current->next = nextNode->next;
            else current = current->next;
        }
        return reverse(head, NULL);
    }
};