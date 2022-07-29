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
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> postorder = new ArrayList<>();
        if(root == null) return postorder;
        TreeNode current = root;
        while(current != null) {
            if(current.right != null) {
                TreeNode rightSubTree = current.right;
                while(rightSubTree.left != null && rightSubTree.left != current)
                    rightSubTree = rightSubTree.left;
                if(rightSubTree.left == null) {
                    postorder.add(current.val);
                    rightSubTree.left = current;
                    current = current.right;
                } else {
                    rightSubTree.left = null;
                    current = current.left;
                }
            } else {
                postorder.add(current.val);
                current = current.left;
            }
        }
        Collections.reverse(postorder);
        return postorder;
    }
}