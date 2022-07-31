/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private static int maxDepth(TreeNode root) {
        return root == null ? 0 : 1 + Math.max(maxDepth(root.left), maxDepth(root.right));
    }
    public boolean isBalanced(TreeNode root) {
        if(root == null) return true;
        if((Math.abs(maxDepth(root.left) - maxDepth(root.right)) > 1)
          || (!isBalanced(root.left) || !isBalanced(root.right)))
            return false;
        return true;
    }
}