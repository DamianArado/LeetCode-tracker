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
    private void inorder(TreeNode root, int[] parent, int[] minDiff) {
        if(root.left != null) inorder(root.left, parent, minDiff);
        if(parent[0] != -1) minDiff[0] = Math.min(minDiff[0], root.val - parent[0]);
        parent[0] = root.val;
        if(root.right != null) inorder(root.right, parent, minDiff);
    }
    public int minDiffInBST(TreeNode root) {
        int[] parent = new int[1], minDiff = new int[1];
        parent[0] = -1;
        minDiff[0] = Integer.MAX_VALUE;
        inorder(root, parent, minDiff);
        return minDiff[0];
    }
}