# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

class Solution:
    def firstBadVersion(self, n: int) -> int:
        start, end, bad = 1, n, -1
        while start <= end:
            mid = start + (end - start) // 2
            if isBadVersion(mid):
                bad = mid
                end = mid - 1
            elif isBadVersion(end): 
                start = mid + 1
            else:
                end = mid - 1
        return bad