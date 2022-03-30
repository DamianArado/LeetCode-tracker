You are given a binary tree with 'N' nodes. Your task is to return the size of the largest subtree of the binary tree which is also a BST.
    
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
/*
Approach 1 -
Go to each node and check if its forming a valid BST or not. If its forming a valid 
BST, then count no. of nodes in it and return the count of max nodes.
TC - O(n^2) SC - O(n) / O(1)

Approach 2 -
At each node, maintain 3 fields: maxSize(max size of BST until this level - going bottom-up), 
maxNode (the largest node to the left), minNode (the smallest node 
to the right) and check if maxNode < current < minNode.
If it is, then it is a valid BST, otherwise its not.

*/
class NodeValue {
  public:
    int maxValue, minValue, maxSize;
    NodeValue(int maxValue, int minValue, int maxSize) {
        this->maxValue = maxValue;
        this->minValue = minValue;
        this->maxSize = maxSize;
    }
};

NodeValue largestBSTSubtree(TreeNode<int>* root) {
    // An empty tree is a valid BST of size 0
    if (!root) {
        return NodeValue(INT_MAX, INT_MIN, 0);
    }
    // Doing a preorder
    // Get values from the left and right subtree of the current tree
    auto left = largestBSTSubtree(root->left);
    auto right = largestBSTSubtree(root->right);
    
    // checking if the current node is bigger than the max node on the left and smaller than
    // the min node on the right
    if(left.maxValue < root->data && root->data < right.minValue) {
        return NodeValue(min(root->data, left.minValue), max(root->data, right.maxValue), 
                         1 + left.maxSize + right.maxSize);
    }
    // Otherwise return [-infinity, infinity] so that any parent cannot be the largest BST
    return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
}


int largestBST(TreeNode<int>* root) 
{
    return largestBSTSubtree(root).maxSize;
}
