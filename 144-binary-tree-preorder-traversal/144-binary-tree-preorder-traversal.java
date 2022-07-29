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
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> preorder = new ArrayList<>();
        if(root == null) return preorder;
        TreeNode current = root;
        while(current != null) {
            if(current.left != null) {
                TreeNode leftSubTree = current.left;
                while(leftSubTree.right != null && leftSubTree.right != current)
                    leftSubTree = leftSubTree.right;
                if(leftSubTree.right == null) {
                    leftSubTree.right = current;
                    preorder.add(current.val);
                    current = current.left;
                } else {
                    leftSubTree.right = null;
                    current = current.right;
                }
            } else {
                preorder.add(current.val);
                current = current.right;
            }
        }
        return preorder;
    }
}