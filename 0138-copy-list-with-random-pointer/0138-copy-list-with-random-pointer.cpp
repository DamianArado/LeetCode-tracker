/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    // make a copy of the original list
    void copyList(Node* head) {
        Node *temp = head, *nxt = head->next;
        while (temp != NULL) {
            Node *copy = new Node(temp->val);
            temp->next = copy;
            copy->next = nxt;
            temp = nxt;
            if (nxt != NULL) 
                nxt = nxt->next;
        }
    }
    
    // each node of original list now point to copy and each node of copy point to the next original node
    void random(Node* head) {
        Node *temp = head;
        while (temp != NULL) {
            if (temp->random) 
                temp->next->random = temp->random->next;
            temp = temp->next->next;
        }
    }
    
    // separate the original and copy linked list
    Node* detach(Node* head) {
        Node* dummy = new Node(-1);
        Node *tail = dummy, *temp = head;
        while (temp != NULL) {
            tail->next = temp->next;
            tail = tail->next;
            temp->next = tail->next;
            temp = temp->next;
        }
        return dummy->next;
    }
    
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) 
            return NULL;
        copyList(head);
        random(head);
        return detach(head);
    }
};