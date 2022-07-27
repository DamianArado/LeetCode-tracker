class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        if n == 1 or k == 1: return nums
        
        maxInWindow = [0] * (n - k + 1)
        dq = deque()
        
        # our sliding window exists in the range [startIdx + 1, endIdx]
        for endIdx in range (0, n):
            startIdx = endIdx - k
            # slide the window forward and hence remove it from the front of the deque
            if dq and dq[0] == startIdx:
                dq.popleft()
            # before adding any index check if we can remove some elements in the deque from the end which 
            # are smaller than this element that is to be added and can be a potential entry in our array
            while dq and nums[endIdx] > nums[dq[-1]]:
                dq.pop()
            # having taken all the above conditions into account now we can add the index inside our deque
            dq.append(endIdx)
            # start adding the candidates as answer 
            # whichever element's index is there on the front in deque is our answer now
            if endIdx >= k - 1:
                maxInWindow[endIdx - k + 1] = nums[dq[0]]
                
        return maxInWindow
                