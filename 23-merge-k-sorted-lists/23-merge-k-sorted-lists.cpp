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
1). Brute-force approach -

Put all the nodes inside a vector and then sort it. After sorting, add elements of vector
sequentially inside the Linked List.

TC -> O(nklognk) SC -> O(nk) considering there are k Linked Lists with average n nodes in each
*/

/*
2). In this approach -

We will maintain k pointers at the start of each sorted linked list. Everytime, we do k comparisons and 
select the smallest node among the k linked lists and add it to the answer. After that, we advance the pointer.

TC -> O(k(n*k)) where n is the average size of each linked list [k x total no. of nodes]
*/

/*
3). In this approach - 

We will maintain a min heap with the k elements at the start of each linked list. To add these k elements to the 
min heap, we need O(logk) TC in the worst-case. And we can take out the smallest element in O(logk) TC and then, we 
will advance its pointer. 

TC -> O(nklogk) where n is the average size of each linked list. SC -> O(k) will be the max size of the min heap
*/
class cmp {
public:
    bool operator () (ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Min Heap
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        ListNode *ans = new ListNode(-1);
        // Subsequent elements will be added to the tail pointer
        ListNode *tail = ans;
        // At max, add k elements to the min heap
        for(int i = 0; i < lists.size(); ++i) {
            if(lists[i] != NULL) q.push(lists[i]);
        }
        while(q.size()) {
            // take out the min element
            ListNode *temp = q.top();
            // add this after the tail node
            tail->next = temp;
            // advance the tail
            tail = temp;
            // go to the next in min heap
            q.pop();
            // push the next element into the heap
            if(temp->next != NULL) q.push(temp->next);
        }
        return ans->next;
    }
};