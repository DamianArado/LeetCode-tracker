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
private:
    ListNode *head;
    int length(ListNode *head) {
        int len = 0;
        while(head != NULL) {
            ++len;
            head = head->next;
        }
        return len;
    }
    TreeNode *constructBST(int left, int right) {
        if(left > right) return NULL;
        int mid = left + (right - left) / 2;
        TreeNode *leftNode = constructBST(left, mid - 1);
        TreeNode *root = new TreeNode(head->val);
        head = head->next; // construct root nodes from left to right
        root->left = leftNode;
        root->right = constructBST(mid + 1, right);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        this->head = head;
        return constructBST(0, length(head) - 1);
    }
};