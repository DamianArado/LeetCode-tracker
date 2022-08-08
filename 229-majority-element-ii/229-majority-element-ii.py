class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        elem1, elem2, cnt1, cnt2, n = -1, -1, 0, 0, len(nums)
        majElem = []
        
        for num in nums:
            if num == elem1: 
                cnt1 += 1
            elif num == elem2:
                cnt2 += 1
            elif cnt1 == 0:
                elem1 = num
                cnt1 = 1
            elif cnt2 == 0:
                elem2 = num
                cnt2 = 1
            else:
                cnt1 -= 1
                cnt2 -= 1
                
        cnt1 = cnt2 = 0
        for num in nums:
            if num == elem1: cnt1 += 1
            if num == elem2: cnt2 += 1
                
        if cnt1 > n // 3: majElem.append(elem1)
        if cnt2 > n // 3 and elem2 is not elem1: majElem.append(elem2)
            
        return majElem
            