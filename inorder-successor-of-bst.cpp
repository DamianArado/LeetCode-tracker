/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>

    class BinaryTreeNode {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

***********************************************************/

BinaryTreeNode<int> *inorderSuccesor(BinaryTreeNode<int> *root, BinaryTreeNode<int> *node) {
    BinaryTreeNode<int> *successor = NULL;
    while(root) {
        if(root->data <= node->data) {
            root = root->right;
        } else {
            successor = root;
            root = root->left;
        }
    }
    return successor;
}
