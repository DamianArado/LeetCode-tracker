class Solution(object):
    def findLength(self, nums1, nums2):
        m = len(nums1)
        n = len(nums2)
        ans = 0
        dp = [0] * (n + 1)
        for i in range(1, m + 1):
            current = [0] * (n + 1)
            for j in range(1, n + 1):
                if nums1[i - 1] == nums2[j - 1]:
                    if dp[j - 1]:
                        current[j] = 1 + dp[j - 1]
                        ans = max(ans, current[j])
                    else:
                        current[j] = 1
                        ans = max(ans, current[j])
                else:
                    current[j] = 0
            dp = current
        return ans
        