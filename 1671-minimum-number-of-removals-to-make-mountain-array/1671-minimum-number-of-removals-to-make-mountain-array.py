class Solution:
    def minimumMountainRemovals(self, nums: List[int]) -> int:
        n = len(nums)
        lis = [1] * (n)
        lds = [1] * (n)
        maxBitonicLength = 1
        
        for idx in range (1, n):
            for prev in range (0, idx):
                if nums[prev] < nums[idx] and lis[idx] < lis[prev] + 1:
                    lis[idx] = lis[prev] + 1
        
        for idx in range (n - 2, -1, -1):
            for prev in range (n - 1, idx, -1):
                if nums[prev] < nums[idx] and lds[idx] < lds[prev] + 1:
                    lds[idx] = lds[prev] + 1
                    
        for idx in range (0, n):
            if lis[idx] > 1 and lds[idx] > 1:
                maxBitonicLength = max(maxBitonicLength, lis[idx] + lds[idx] - 1)
                
        return n - maxBitonicLength
                
                