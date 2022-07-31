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
    private static int calculateHeight(TreeNode root, int[] diameter) {
        if(root == null) return 0;
        
        int leftHeight = calculateHeight(root.left, diameter);
        int rightHeight = calculateHeight(root.right, diameter);
        
        diameter[0] = Math.max(diameter[0], leftHeight + rightHeight);
        return 1 + Math.max(leftHeight, rightHeight);
    }
    public int diameterOfBinaryTree(TreeNode root) {
        int diameter[] = new int[1];
        calculateHeight(root, diameter);
        return diameter[0];
    }
}