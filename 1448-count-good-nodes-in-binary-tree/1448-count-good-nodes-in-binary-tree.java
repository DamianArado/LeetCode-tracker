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
    private int[] dfsHelper(TreeNode root, int[] goodNodes, int maxTillNow) {
        if(root == null) return goodNodes;
        if(root.val >= maxTillNow) {
            maxTillNow = root.val;
            goodNodes[0]++;
        }
        dfsHelper(root.left, goodNodes, maxTillNow);
        dfsHelper(root.right, goodNodes, maxTillNow);
        return goodNodes;
    }
    public int goodNodes(TreeNode root) {
        int[] goodGuys = {0};
        int[] ans = dfsHelper(root, goodGuys, Integer.MIN_VALUE);
        return ans[0];
    }
}