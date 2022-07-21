class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        if target >= letters[-1]: 
            return letters[0]
        l, r = 0, len(letters) - 1
        while l < r:
            m = (l+r) // 2
            if letters[m] > target:
                r = m
            else:
                l = m + 1
        return letters[l]