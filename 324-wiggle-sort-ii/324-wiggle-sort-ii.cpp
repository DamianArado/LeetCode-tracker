class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int> maxHeap(nums.begin(), nums.end());
        for(int i = 1; i < n; i += 2) {
            nums[i] = maxHeap.top();
            maxHeap.pop();
        }
        for(int i = 0; i < n; i += 2) {
            nums[i] = maxHeap.top();
            maxHeap.pop();
        }
    }
};