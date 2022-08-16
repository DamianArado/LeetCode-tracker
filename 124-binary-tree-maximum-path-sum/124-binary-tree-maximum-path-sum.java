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
    private static int calculate(TreeNode root, int[] maxSum) {
        if(root == null) return 0;
        int leftPathSum = Math.max(0, calculate(root.left, maxSum));
        int rightPathSum = Math.max(0, calculate(root.right, maxSum));
        maxSum[0] = Math.max(maxSum[0], root.val + leftPathSum + rightPathSum);
        return root.val + Math.max(leftPathSum, rightPathSum);
    }
    public int maxPathSum(TreeNode root) {
        int maxSum[] = new int[1];
        maxSum[0] = Integer.MIN_VALUE;
        calculate(root, maxSum);
        return maxSum[0];
    }
}