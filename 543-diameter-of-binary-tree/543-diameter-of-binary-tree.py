# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def calculateHeight(self, root: Optional[TreeNode], diameter: list) -> int:
        if not root: return 0
        leftHeight = self.calculateHeight(root.left, diameter)
        rightHeight = self.calculateHeight(root.right, diameter)
        diameter[0] = max(diameter[0], leftHeight + rightHeight)
        return 1 + max(leftHeight, rightHeight)
    
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        diameter = [0]
        self.calculateHeight(root, diameter)
        return diameter[0]