# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from queue import Queue
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        zigZag = []
        if not root: return zigZag
        q = Queue()
        q.put(root)
        leftToRight = True
        while q.qsize():
            n = q.qsize()
            level = [0] * (n)
            for i in range (n):
                current = q.get()
                idx = i if leftToRight else n - i - 1
                level[idx] = current.val
                if current.left: q.put(current.left)
                if current.right: q.put(current.right)
            leftToRight = not leftToRight
            zigZag.append(level)
        return zigZag