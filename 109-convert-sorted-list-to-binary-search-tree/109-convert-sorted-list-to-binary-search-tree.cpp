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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    // pointer to first element of BST
    ListNode* head;    
public:
    
    int length(ListNode* head) {  // number of elements in LL
        int ans = 0;
        while(head) {
            head = head->next;
            ans++;
        }
        return ans;
    }
    
    TreeNode* buildBST(int left, int right) {
        if(left > right) return NULL;
        int mid = left + (right - left) / 2;
        // building from left to right
        TreeNode* leftNode = buildBST(left, mid - 1);
        // now root is the mid node, after building left subtree, now head points to the mid element
        TreeNode* root = new TreeNode(head->val);
        head = head->next; // go to next after taking root's value
        root->left = leftNode;
        // build the right node of the root
        root->right = buildBST(mid + 1, right);
        // returns pointer to root of the height-balanced BST
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        this->head = head;
        return buildBST(0, length(head) - 1);
    }
};