class Solution {
public:
    // TC - O(nlogk) SC - O(k)
    int findKthLargest(vector<int>& nums, int k) {
        // construct a min heap
        priority_queue<int, vector<int>, greater<int>> pq;
        // go to each index of nums and add elements to pq such that pq.size <= k
        for(int i = 0; i < nums.size(); ++i) {
            pq.push(nums[i]);
            if(pq.size() > k)
                pq.pop();
        }
        // the topmost element would be the k-th largest
        return pq.top();
    }
};