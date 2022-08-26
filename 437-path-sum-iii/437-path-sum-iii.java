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
    private int getPaths(TreeNode root, long sum, int target, HashMap<Long, Integer> store) {
        if(root == null) return 0;
        sum += root.val;
        int ans = store.getOrDefault(sum - target, 0);
        store.put(sum, store.getOrDefault(sum, 0) + 1);
        ans += getPaths(root.left, sum, target, store) + getPaths(root.right, sum, target, store);
        store.put(sum, store.get(sum) - 1);
        return ans;
    }
    public int pathSum(TreeNode root, int targetSum) {
        var store = new HashMap<Long, Integer>();
        store.put((long)0, 1);
        return getPaths(root, 0, targetSum, store);
    }
}