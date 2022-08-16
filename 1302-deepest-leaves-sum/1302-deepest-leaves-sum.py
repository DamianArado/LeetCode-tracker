# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findDeepestLevel(self, root: TreeNode) -> int:
        return 0 if root == None else 1 + max(self.findDeepestLevel(root.left), self.findDeepestLevel(root.right))
    
    def deepestLeavesSumH(self, root: TreeNode, deepestLevel: list, currentLevel: int) -> int:
        if not root: return 0
        if not root.left and not root.right:
            return root.val if deepestLevel[0] == currentLevel else 0
        return self.deepestLeavesSumH(root.left, deepestLevel, currentLevel + 1) + self.deepestLeavesSumH(root.right, deepestLevel, currentLevel + 1)
    
    def deepestLeavesSum(self, root: Optional[TreeNode]) -> int:
        deepestLevel = [0]
        deepestLevel[0] = self.findDeepestLevel(root) - 1
        return self.deepestLeavesSumH(root, deepestLevel, 0) 