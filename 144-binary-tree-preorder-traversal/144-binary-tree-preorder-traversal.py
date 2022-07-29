# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        preorder = []
        if not root: return preorder
        current = root
        while current:
            if current.left:
                leftSubTree = current.left
                while leftSubTree.right and leftSubTree.right != current:
                    leftSubTree = leftSubTree.right
                if not leftSubTree.right:
                    leftSubTree.right = current
                    preorder.append(current.val)
                    current = current.left
                else:
                    leftSubTree.right = None
                    current = current.right
            else:
                preorder.append(current.val)
                current = current.right
        return preorder