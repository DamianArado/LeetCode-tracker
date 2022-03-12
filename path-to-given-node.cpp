/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 
Problem Description

Given a Binary Tree A containing N nodes.

You need to find the path from Root to a given node B.

NOTE:

No two nodes in the tree have same data values.
You can assume that B is present in the tree A and a path always exists.


Problem Constraints
 1 <= N <= 105 

 1 <= Data Values of Each Node <= N

 1 <= B <= N



Input Format
First Argument represents pointer to the root of binary tree A.

Second Argument is an integer B denoting the node number.



Output Format
Return an one-dimensional array denoting the path from Root to the node B in order.
 */

bool getPath(TreeNode* root, vector<int> &arr, int B) {
    if(!root) return false;
    arr.emplace_back(root->val); // add it
    if(root->val == B) return true; // return from here
    if(getPath(root->left, arr, B) || getPath(root->right, arr, B)) return true; // if any of the left or right calls return true
    arr.pop_back(); // else both returned false / both are null so return false
    return false;
}

vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> arr;
    if(!A) return arr;
    getPath(A, arr, B);
    return arr;
}
