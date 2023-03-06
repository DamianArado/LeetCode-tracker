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
        
        int left = calculateHeight(root.left, diameter);
        int right = calculateHeight(root.right, diameter);
        
        diameter[0] = Math.max(diameter[0], left + right);
        return 1 + Math.max(left, right);
    }
    public int diameterOfBinaryTree(TreeNode root) {
        int diameter[] = new int[1];
        calculateHeight(root, diameter);
        return diameter[0];
    }
}