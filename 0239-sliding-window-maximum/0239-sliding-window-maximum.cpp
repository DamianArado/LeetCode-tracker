class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1 or k == 1) return nums;
        
        vector<int> maxInWindow;
        deque<int> dq;
        
        // our sliding window exists in the range [startIdx + 1, endIdx]
        for(int endIdx = 0; endIdx < n; ++endIdx) {
            int startIdx = endIdx - k;
            // slide the window forward and hence remove it from the front of the deque
            if(!dq.empty() and dq.front() == startIdx)
                dq.pop_front();
            // before adding any index check if we can remove some elements in the deque from the end which 
            // are smaller than this element that is to be added and can be a potential entry in our array
            while(!dq.empty() and nums[endIdx] > nums[dq.back()])
                dq.pop_back();
            // having taken all the above conditions into account now we can add the index inside our deque
            dq.push_back(endIdx);
            // start adding the candidates as answer 
            // whichever element's index is there on the front in deque is our answer now
            if(endIdx >= k - 1) 
                maxInWindow.push_back(nums[dq.front()]);
        }
        
        return maxInWindow;
    }
};