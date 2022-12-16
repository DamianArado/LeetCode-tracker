class Solution(object):
    def isBalanced(self, root):
        def height(root):
            if not root: return 0
            left = height(root.left)
            right = height(root.right)
            return 1 + max(left, right)
        if not root: return True
        if abs(height(root.left) - height(root.right)) > 1 or not self.isBalanced(root.left) or not self.isBalanced(root.right):
            return False
        return True
        