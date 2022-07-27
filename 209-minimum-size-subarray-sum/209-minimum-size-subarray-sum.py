class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        n, currentSum, minSubArr, i = len(nums), 0, 1e7, 0
        for j in range(n):
            currentSum += nums[j];
            while currentSum >= target: 
                minSubArr = min(minSubArr, j - i + 1);
                currentSum -= nums[i];
                i += 1
        if minSubArr == 1e7: return 0
        else: return minSubArr