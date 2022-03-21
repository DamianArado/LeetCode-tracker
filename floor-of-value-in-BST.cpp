/*

You are given a BST (Binary search tree) with’ N’ number of nodes and a value ‘X’. Your task is to find the greatest value 
node of the BST which is smaller than or equal to ‘X’.
Note :‘X’ is not smaller than the smallest node of BST .

TC - O(log n) SC - O(1)

*/

/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int floorInBST(TreeNode<int> * root, int X) {
    int floor;
    while(root) {
        if(root->val <= X) {
            floor = root->val;
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return floor;
}
