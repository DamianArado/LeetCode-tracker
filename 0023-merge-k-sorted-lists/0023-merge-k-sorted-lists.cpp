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
Then, add them inside the linked list.
TC: O(nk*log(nk)) ; SC: O(nk)

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

Approach 2: 
We will maintain k pointers at the start of each sorted linked list. Everytime, we do k comparisons and 
select the smallest node among the k linked lists and add it to the answer. After that, we advance the 
pointer.

TC -> O(k*(n*k)) where n is the average size of each linked list [k x total no. of nodes]

Approach 3:
Use a min heap to store k pointers to linked lists and add the min one to the answer.
TC -> O(nk*logk) for k insertions nk no. of times ; SC -> O(k) for min heap

*/
class comparator {
public:
  bool operator() (ListNode *a, ListNode *b) {
      return a->val > b->val;  // very important here
  }  
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, comparator> minHeap;
        for(int i = 0; i < size(lists); ++i) 
            if(lists[i] != NULL) 
                minHeap.emplace(lists[i]);
        ListNode *ans = new ListNode(-1);
        ListNode *tail = ans; // this keeps on adding nodes to itself
        while(!minHeap.empty()) {
            ListNode *temp = minHeap.top();
            minHeap.pop();
            tail->next = temp;
            tail = temp;
            // keeps adding the next node to make sure we are considering the smallest one
            if(temp->next != NULL) minHeap.emplace(temp->next);
        }
        ans = ans->next;
        return ans;
    }
};