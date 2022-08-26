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
/**

Example: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8

           10[10]
           /     \
        5[15]   -3[7]
       /   \         \
     3[18]  2[17]    11[18]
     /   \      \
  3[21] -2[16]  1[18]
  
  10 - 8 = 2 (❎)         16 - 8 = 8 (❎)
  15 - 8 = 7 (✅)         17 - 8 = 7 (❎)
  18 - 8 = 10 (✅)        18 - 8 = 10 (✅)
  21 - 8 = 13 (❎)        7 - 8 = -1 (❎)
    
Calculate the prefix sum at each node and store it inside a map
At each node, check whether prefixSum - target is present inside the map
which basically means that you have visited this path sum already in your current path

*/
class Solution {
private:
    int helper(TreeNode *root, long prefixSum, int target, unordered_map<long, int> &store) {
        if(!root) return 0;
        prefixSum += root->val;
        int ans = store[prefixSum - target];
        store[prefixSum]++;
        ans += helper(root->left, prefixSum, target, store) + helper(root->right, prefixSum, target, store);
        store[prefixSum]--;
        return ans;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long, int> store;
        store[0] = 1;
        return helper(root, 0, targetSum, store);
    }
};