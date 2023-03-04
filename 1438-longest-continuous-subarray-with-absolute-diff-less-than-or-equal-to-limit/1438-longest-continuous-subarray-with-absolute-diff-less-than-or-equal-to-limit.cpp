class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = size(nums), ans = 1, left = 0;
        deque<int> minDq, maxDq;
        for(int right = 0; right < n; ++right) {
            // if we found an element lesser than the one at back of min deque
            while(!minDq.empty() and nums[minDq.back()] >= nums[right])
                minDq.pop_back();
            // if we found an element greater than the one at back of max deque
            while(!maxDq.empty() and nums[maxDq.back()] <= nums[right])
                maxDq.pop_back();
            // push the current element
            minDq.push_back(right);
            maxDq.push_back(right);
            // if the current window doesnt satisfy the limit
            while(nums[maxDq.front()] - nums[minDq.front()] > limit) {
                // shrink the winodw
                ++left;
                // remove those indices as well
                if(left > minDq.front()) minDq.pop_front();
                if(left > maxDq.front()) maxDq.pop_front();
            }
            // update answer
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};