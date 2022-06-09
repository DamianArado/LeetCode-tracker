class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        // first create a max heap where we'll store the -ve of distances, heights[i + 1] - heights[i]
        priority_queue<int> maxHeap;
        // iterate over the heights array and see upto which index we can reach at max
        int n = heights.size(), i = 0, jumpHeight = 0;
        for( ; i < n - 1; ++i) {
            jumpHeight = heights[i + 1] - heights[i];
            if(jumpHeight <= 0) continue;  // no need to use any brick or ladder
            maxHeap.push(-jumpHeight);  // min height difference stays on the top
            if(maxHeap.size() > ladders)  // time to use our bricks for the least -ve on top, the ones lower will be dealt w/ ladders
                bricks += maxHeap.top(), maxHeap.pop();
            if(bricks < 0) return i;  // time to return
        }
        return i;
    }
};