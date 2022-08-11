class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        n, heap = len(nums), []
        for num in nums: 
            heappush(heap, -1 * num)
        for i in range (1, n, 2):
            nums[i] = -1 * heap[0]
            heappop(heap)
        for i in range (0, n, 2):
            nums[i] = -1 * heap[0]
            heappop(heap)
        return nums