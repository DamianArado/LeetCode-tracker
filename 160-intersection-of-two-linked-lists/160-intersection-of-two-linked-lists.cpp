/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA, *b = headB;
        while(a != b) {
            if(a == NULL) a = headB;
            else a = a->next;
            if(b == NULL) b = headA;
            else b = b->next;
        }
        return a;
    }
};

/*
Approach 1 -

Take headA and traverse whole of listB to check if headA occurs. In worst-case,
TC would be O(mn), SC will be O(1).

Approach 2 -

Traverse the whole of listA and store all its elements inside a set. Now, while traversing the 
listB, check if that node is already present inside the set. If its present return that node.
In worst case, TC -> O(m+n), SC -> O(m)

Approach 3 -

Calculate lengths of both linked lists. And make it equal: for example len1 = 3 and len2 = 5, so make 
sure to bring headB 2 positions forward so that len1 = len2. Now, traverse forwards in both of the LLs 
and check whether they are equal. Return the node immediately where they are equal

TC -> O(max(m,n)), SC -> O(1)
*/