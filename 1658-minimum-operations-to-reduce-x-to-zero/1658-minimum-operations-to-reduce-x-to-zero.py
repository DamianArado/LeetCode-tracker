class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        sumArr, n = 0, len(nums)
        for num in nums: 
            sumArr += num
        k, currentSum, longestSubArr, i = sumArr - x, 0, 0, 0
        if k == 0: return n
        for j in range(n):
            currentSum += nums[j]
            if currentSum > k:
                while currentSum > k and i <= j:
                    currentSum -= nums[i]
                    i += 1
            if currentSum == k:
                longestSubArr = max(longestSubArr, j - i + 1)
        if longestSubArr == 0: return -1
        return n - longestSubArr
        
            