class Solution
{
  public:
    // Function to merge two doubly linked lists
    Node* mergeDLL(Node* listOne, Node* listTwo) {
        if(!listOne) return listTwo;
        if(!listTwo) return listOne;
        // change connections
        Node* lastListOne = listOne->left;
        Node* lastListTwo = listTwo->left;
        
        lastListOne->right = listTwo;
        listTwo->left = lastListOne;
        listOne->left = lastListTwo;
        lastListTwo->right = listOne;
        
        return listOne;
    }
    //Function to convert binary tree into circular doubly linked list.
    Node *bTreeToCList(Node *root) {
        if(!root) return NULL;
        // doing a preorder traversal to do the conversion
        Node* leftSubtree = bTreeToCList(root->left);
        Node* rightSubtree = bTreeToCList(root->right);
        // point the left and right of a root to itself
        root->left = root->right = root;
        // first merge the left subtree and root
        Node* leftToRoot = mergeDLL(leftSubtree, root);
        // then merge this result with the right subtree
        return mergeDLL(leftToRoot, rightSubtree);
    }
};ewwq
