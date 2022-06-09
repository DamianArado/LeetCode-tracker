class Solution {
    public int furthestBuilding(int[] heights, int bricks, int ladders) {
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        int n = heights.length, i = 0, jumpHeight = 0;
        for( ; i < n - 1; ++i) {
            jumpHeight = heights[i + 1] - heights[i];
            if(jumpHeight <= 0) 
                continue;
            minHeap.add(jumpHeight);
            if(minHeap.size() > ladders)
                bricks -= minHeap.poll();
            if(bricks < 0)
                return i;
        }
        return i;
    }
}