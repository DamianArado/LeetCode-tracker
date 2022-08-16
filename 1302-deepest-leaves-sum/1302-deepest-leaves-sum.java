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
    private static int findDeepestLevel(TreeNode root) {
        return root == null ? 0 : 1 + Math.max(findDeepestLevel(root.left), findDeepestLevel(root.right));
    }
    private static int deepestLeavesSum(TreeNode root, int[] deepestLevel, int currentLevel) {
        if(root == null) return 0;
        if(root.left == null && root.right == null)
            return deepestLevel[0] == currentLevel ? root.val : 0;
        return deepestLeavesSum(root.left, deepestLevel, currentLevel + 1)
            + deepestLeavesSum(root.right, deepestLevel, currentLevel + 1);
    }
    public int deepestLeavesSum(TreeNode root) {
        int deepestLevel[] = new int[1];
        deepestLevel[0] = findDeepestLevel(root) - 1;
        return deepestLeavesSum(root, deepestLevel, 0);
    }
}