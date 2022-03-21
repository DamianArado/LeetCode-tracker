/*
    Ceil of an integer is the closest integer greater than or equal to a given number.
    For example:
    arr[] = {1, 2, 5, 7, 8, 9}, key = 3.
    The closest integer greater than 3 in the given array is 5. So, its ceil value in the given array is 5.
    
    TC - O(log n), SC - O(1)
    
    Given a binary search tree and an integer (a particular key) in the tree. Return its ceil value.
*/

/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

int findCeil(BinaryTreeNode<int> *node, int x){
    int ceil = -1;
    while(node) {
        if(node->data >= x) {
            ceil = node->data;
            node = node->left;
        } else {
            node = node->right;
        }
    }
    return ceil;
}
