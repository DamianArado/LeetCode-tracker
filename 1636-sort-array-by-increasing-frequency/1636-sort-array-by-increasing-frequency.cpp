class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums;
        unordered_map<int,int> freq;
        for(int i = 0; i < n; ++i)
            freq[nums[i]] += 1;
        priority_queue<pair<int,int>> maxHeap;
        for(auto &i : freq)
            maxHeap.push({-(i.second), i.first});
        nums.clear();
        while(!maxHeap.empty()) {
            for(int i = 0; i < -(maxHeap.top().first); ++i)
                nums.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return nums;
    }
};