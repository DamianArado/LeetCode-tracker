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
public:
    Node* copyRandomList(Node* head) {
        // firstly make a linked list of copied nodes
        Node *temp = head;
        // store copy nodes having same values: {A, A'}, {B, B'}, {C, C'}, etc 
        unordered_map<Node*, Node*> m;
        while(temp) {
            Node *copy = new Node(temp->val);
            m[temp] = copy;
            temp = temp->next;
        }
        temp = head;
        // make connections using the copy nodes: deep-copy
        while(temp) {
            m[temp]->next = m[temp->next];
            m[temp]->random = m[temp->random];
            temp = temp->next;
        }
        // return copy's head: m[head] === m[head']
        return m[head];
    }
};