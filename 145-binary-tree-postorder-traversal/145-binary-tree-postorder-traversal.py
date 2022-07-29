# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        postorder = []
        if not root: return postorder
        current = root
        while current:
            if current.right:
                rightSubTree = current.right
                while rightSubTree.left and rightSubTree.left is not current:
                    rightSubTree = rightSubTree.left
                if rightSubTree.left is None:
                    postorder.append(current.val)
                    rightSubTree.left = current
                    current = current.right
                else:
                    rightSubTree.left = None
                    current = current.left
            else:
                postorder.append(current.val)
                current = current.left
        postorder = reversed(postorder)
        return postorder