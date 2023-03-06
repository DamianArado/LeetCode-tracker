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
    public List<Integer> inorderTraversal(TreeNode root) {
        var inorder = new ArrayList<Integer>();
        if(root == null) return inorder;
        TreeNode current = root;
        
        while(current != null) {
            if(current.left != null) {
                TreeNode leftSubTree = current.left;
                while(leftSubTree.right != null && leftSubTree.right != current) 
                    leftSubTree = leftSubTree.right;
                
                if(leftSubTree.right == null) {
                    leftSubTree.right = current;
                    current = current.left;
                } else {
                    leftSubTree.right = null;
                    inorder.add(current.val);
                    current = current.right;
                }
            } else {
                inorder.add(current.val);
                current = current.right;
            }
        }
        return inorder;
     }
}