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
    private int maxDiff(TreeNode root, int maxNode, int minNode) {
        if(root == null) return maxNode - minNode;
        minNode = Math.min(minNode, root.val);
        maxNode = Math.max(maxNode, root.val);
        return Math.max(maxDiff(root.left, maxNode, minNode), maxDiff(root.right, maxNode, minNode));
    }
    public int maxAncestorDiff(TreeNode root) {
        return maxDiff(root, 0, 100000);
    }
}