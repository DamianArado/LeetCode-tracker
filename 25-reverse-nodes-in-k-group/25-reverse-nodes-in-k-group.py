# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        prev, current = None, head
        for _ in range (k):
            if current is None:
                return head
            current = current.next
        current = head
        for _ in range (k):
            nxt = current.next
            current.next = prev
            prev = current
            current = nxt
        head.next = self.reverseKGroup(current, k)
        return prev