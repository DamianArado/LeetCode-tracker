class Solution:
    def pivotInteger(self, n: int) -> int:
        if n == 1: return 1
        sums, start, end = n * (n + 1) / 2, 0, n
        while start < end: 
            mid = start + (end - start) // 2
            if mid * mid == sums: return mid
            elif mid * mid > sums: end = mid - 1
            else: start = mid + 1
        return -1