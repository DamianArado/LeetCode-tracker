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
    private TreeNode buildTree(int[] inorder, int inStart, int inEnd, int[] postorder, int postStart, 
                              int postEnd, HashMap<Integer, Integer> inMappings) {
        if(inStart > inEnd || postStart > postEnd) return null;
        TreeNode root = new TreeNode(postorder[postEnd]);
        int inorderRoot = inMappings.get(root.val);
        int numTowardsLeft = inorderRoot - inStart;
        root.left = buildTree(inorder, inStart, inorderRoot - 1, 
                              postorder, postStart, postStart + numTowardsLeft - 1, inMappings);
        root.right = buildTree(inorder, inorderRoot + 1, 
                               inEnd, postorder, postStart + numTowardsLeft, postEnd - 1, inMappings);
        return root;
    }
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        int n1 = inorder.length, n2 = postorder.length;
        var inMappings = new HashMap<Integer, Integer>();
        for(int i = 0; i < n1; ++i)
            inMappings.put(inorder[i], i);
        return buildTree(inorder, 0, n1 - 1, postorder, 0, n2 - 1, inMappings);
    }
}