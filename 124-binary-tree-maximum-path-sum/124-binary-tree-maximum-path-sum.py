# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def calculate(self, root: Optional[TreeNode], maxSum: list) -> int:
        if not root: return 0
        leftPathSum = max(0, self.calculate(root.left, maxSum))
        rightPathSum = max(0, self.calculate(root.right, maxSum))
        maxSum[0] = max(maxSum[0], root.val + leftPathSum + rightPathSum)
        return root.val + max(leftPathSum, rightPathSum)
    
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        maxSum = [-1e9]
        self.calculate(root, maxSum)
        return maxSum[0]