class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        if target >= letters[-1]: 
            return letters[0]
        left, right = 0, len(letters) - 1
        while left < right:
            mid = left + (right - left) // 2
            if letters[mid] > target:
                right = mid
            else:
                left = mid + 1
        return letters[left]