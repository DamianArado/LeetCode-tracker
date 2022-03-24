# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def find(self, root, left, right): 
        if root is None:
            return True    
        if root.val >= right or root.val <= left:
            return False 
        return self.find(root.left, left, root.val) and self.find(root.right, root.val, right)
    
    def isValidBST(self, root):  
        return self.find(root, float("-inf"), float("inf"))
        