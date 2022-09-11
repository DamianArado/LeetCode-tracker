class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        n1, n2 = len(nums1), len(nums2)
        if n1 > n2: return self.findMedianSortedArrays(nums2, nums1)
        start, end = 0, n1
        while start <= end:
            cut1 = start + (end - start) // 2
            cut2 = (n1 + n2 + 1) // 2 - cut1
            left1 = nums1[cut1 - 1] if cut1 != 0 else -1e7            
            left2 = nums2[cut2 - 1] if cut2 != 0 else -1e7            
            right1 = nums1[cut1] if cut1 != n1 else 1e7            
            right2 = nums2[cut2] if cut2 != n2 else 1e7
            if left1 <= right2 and left2 <= right1:
                if (n1 + n2) % 2 == 0:
                    return (max(left1, left2) + min(right1, right2)) / 2
                else:
                    return max(left1, left2)
            elif left1 > right2: end = cut1 - 1
            else: start = cut1 + 1
        return 0.0