# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        inorder = []
        if not root: return inorder
        current = root
        while current:
            if current.left:
                leftSubTree = current.left
                while leftSubTree.right and leftSubTree.right != current:
                    leftSubTree = leftSubTree.right
                if not leftSubTree.right:
                    leftSubTree.right = current
                    current = current.left
                else:
                    leftSubTree.right = None
                    inorder.append(current.val)
                    current = current.right
            else:
                inorder.append(current.val)
                current = current.right
        return inorder