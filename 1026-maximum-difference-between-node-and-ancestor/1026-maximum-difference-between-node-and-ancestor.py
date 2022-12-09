# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        def maxDiff(root: TreeNode, maxNode: int, minNode: int) -> int:
            if not root:
                return maxNode - minNode
            minNode, maxNode = min(minNode, root.val), max(maxNode, root.val)
            return max(maxDiff(root.left, maxNode, minNode), maxDiff(root.right, maxNode, minNode))
        return maxDiff(root, 0, 1e9)