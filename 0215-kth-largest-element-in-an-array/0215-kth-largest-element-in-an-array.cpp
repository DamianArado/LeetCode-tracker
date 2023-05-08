class Solution {
public:
    // TC - O(nlogk) SC - O(k)
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(const int &num : nums) {
            minHeap.emplace(num);
            if(minHeap.size() > k) minHeap.pop();
        }
        return minHeap.top();
    }
};