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
    public int findBottomLeftValue(TreeNode root) {
        TreeNode current = root;
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        q.add(current);
        while(!q.isEmpty()) {
            current = q.poll();
            if(current.right != null) q.add(current.right);
            if(current.left != null) q.add(current.left);
        }
        return current.val;
    }
}