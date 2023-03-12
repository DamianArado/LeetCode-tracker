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
/*

Approach 1: Put all the nodes inside a vector and sort them.
Then, add them inside the linked lists.


*/
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> nodes;
        for(ListNode *list : lists) {
            while(list != NULL) {
                nodes.emplace_back(list->val);
                list = list->next;
            }
        }
        sort(begin(nodes), end(nodes));
        ListNode *dummy = new ListNode(-1);
        ListNode *temp = dummy;
        for(int &i : nodes) {
            ListNode *nxt = new ListNode(i);
            temp->next = nxt;
            temp = nxt;
        }
        return dummy->next;
    }
};