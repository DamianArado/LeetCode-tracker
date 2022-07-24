"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, root: 'Optional[Node]') -> 'Optional[Node]':
        if not root: return root
        
        self.current = root
        
        while self.current:
            
            # this will always be the first node of any level
            self.level1stNode = self.current
            
            # this runs until we iterate over all the nodes of any level
            while self.current:
                
                # this links the child nodes (L child -> next = R child) of the same parent node
                if self.current.left:
                    self.current.left.next = self.current.right
                    
                # this checks whether there are more nodes towards right at the same level
                if self.current.right and self.current.next:
                    self.current.right.next = self.current.next.left
                    
                # move on the next node of the current level (L -> R)
                self.current = self.current.next
            
            # move onto the first node of the next level
            self.current = self.level1stNode.left
            
        return root