# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def longestUnivaluePath(self, root: Optional[TreeNode]) -> int:
        self.longest = 0;
        def traverse(root, parentVal):
            if not root: return 0;
            left, right = traverse(root.left, root.val), traverse(root.right, root.val);
            self.longest = max(self.longest, left + right);
            return 1 + max(left, right) if root.val == parentVal else 0;
        traverse(root, -1);
        return self.longest;