class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int n = nums.length;
        if(n == 1 || k == 1) return nums;
        
        int[] maxInWindow = new int[n - k + 1];
        Deque<Integer> dq = new ArrayDeque<>();
        
        // our sliding window exists in the range [startIdx + 1, endIdx]
        for(int endIdx = 0; endIdx < n; ++endIdx) {
            int startIdx = endIdx - k;
            // slide the window forward and hence remove it from the front of the deque
            if(!dq.isEmpty() && dq.getFirst() == startIdx)
                dq.removeFirst();
            // before adding any index check if we can remove some elements in the deque from the end which 
            // are smaller than this element that is to be added and can be a potential entry in our array
            while(!dq.isEmpty() && nums[endIdx] > nums[dq.getLast()])
                dq.removeLast();
            // having taken all the above conditions into account now we can add the index inside our deque
            dq.add(endIdx);
            // start adding the candidates as answer 
            // whichever element's index is there on the front in deque is our answer now
            if(endIdx >= k - 1)
                maxInWindow[endIdx - k + 1] = nums[dq.getFirst()];
        }
        return maxInWindow;
    }
}