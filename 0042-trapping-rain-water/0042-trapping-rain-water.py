class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        if n == 1: return 0
        left, right, ans = 1, n - 2, 0
        maxFromLeft, maxFromRight = height[0], height[n - 1]
        while left <= right:
            if maxFromLeft <= maxFromRight:
                if maxFromLeft < height[left]:
                    maxFromLeft = height[left]
                else:
                    ans += (maxFromLeft - height[left])
                left += 1
            else:
                if maxFromRight < height[right]:
                    maxFromRight = height[right]
                else: 
                    ans += (maxFromRight - height[right])
                right -= 1
        return ans
            