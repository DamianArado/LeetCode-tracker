# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def longestZigZag(self, root: Optional[TreeNode]) -> int:
        l, r, ans = 0, 0, [0]
        def dfs(root, l, r, ans):
            if root == None: return
            ans[0] = max(ans[0], l, r)
            dfs(root.left, 0, l + 1, ans)
            dfs(root.right, r + 1, 0, ans)
        dfs(root, l, r, ans)
        return ans[0]