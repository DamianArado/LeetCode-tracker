class Solution:
    def maxJump(self, stones: List[int]) -> int:
        maxDiff, n =  stones[1] - stones[0], len(stones);
        for i in range(2, n): maxDiff = max(maxDiff, stones[i] - stones[i - 2]);
        for i in range(3, n): maxDiff = max(maxDiff, stones[i] - stones[i - 2]);
        return maxDiff;