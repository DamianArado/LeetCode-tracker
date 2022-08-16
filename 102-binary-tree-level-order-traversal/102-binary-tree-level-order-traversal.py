# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from queue import Queue
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        levelOrder = []
        if not root: return levelOrder
        q = Queue()
        q.put(root)
        while q.qsize():
            n = q.qsize()
            level = []
            for i in range (n):
                current = q.get()
                level.append(current.val)
                if current.left: q.put(current.left)
                if current.right: q.put(current.right)
            levelOrder.append(level)
        return levelOrder
        