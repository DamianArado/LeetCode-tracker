class Solution:
    def longestMountain(self, arr: List[int]) -> int:
        n = len(arr)
        idx = 1
        up = 0
        down = 0
        maxMountain = 0
        
        while idx < n:
            while idx < n and arr[idx - 1] == arr[idx]:
                idx += 1
            up = 0
            while idx < n and arr[idx - 1] < arr[idx]:
                up += 1
                idx += 1
            down = 0
            while idx < n and arr[idx - 1] > arr[idx]:
                down += 1
                idx += 1
            if up > 0 and down > 0:
                maxMountain = max(maxMountain, up + down + 1)
                
        return maxMountain