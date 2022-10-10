# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumRootToLeaf(self, root: Optional[TreeNode], ans: int = 0) -> int:
            if not root: return 0;
            ans = ans * 2 + root.val;
            return ans if root.left == root.right else self.sumRootToLeaf(root.left, ans) + self.sumRootToLeaf(root.right, ans);