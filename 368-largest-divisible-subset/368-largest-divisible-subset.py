class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        n = len(nums)
        dp = [1] * (n)
        hashArr = list(range(0, n))
        maxLIS = 1
        lastIdx = 0
        nums = sorted(nums, reverse = False)
        
        for idx in range (1, n):
            for prev in range (0, idx):
                if nums[idx] % nums[prev] == 0 and dp[idx] < 1 + dp[prev]:
                    dp[idx] = 1 + dp[prev]
                    hashArr[idx] = prev
            if dp[idx] > maxLIS:
                maxLIS = dp[idx]
                lastIdx = idx
        
        lds = []
        lds.append(nums[lastIdx])
        while lastIdx != hashArr[lastIdx]:
            lastIdx = hashArr[lastIdx]
            lds.append(nums[lastIdx])
        lds = reversed(lds);
        return lds
        