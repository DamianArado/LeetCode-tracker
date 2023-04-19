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
    private void dfs(TreeNode root, int l, int r, int[] ans) {
        if(root == null) return;
        ans[0] = Math.max(ans[0], Math.max(l, r));
        dfs(root.left, 0, l + 1, ans);
        dfs(root.right, r + 1, 0, ans);
    }
    public int longestZigZag(TreeNode root) {
        int left = 0, right = 0;
        int[] ans = new int[1];
        dfs(root, left, right, ans);
        return ans[0];
    }
}