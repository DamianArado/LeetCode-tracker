class Solution:
    def largestSumAfterKNegations(self, nums: List[int], k: int) -> int:
        maxSum, heap = 0, []
        for num in nums:
            heappush(heap, num)
        while k > 0:
            num = heap[0]
            heappop(heap)
            heappush(heap, -1 * num)
            k -= 1
        while len(heap):
            maxSum += heap[0]
            heappop(heap)
        return maxSum