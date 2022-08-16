"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""
from queue import Queue
class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
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
                for child in current.children:
                    q.put(child)
            levelOrder.append(level)
        return levelOrder