// TC - O(nlogk), SC - O(k)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: covert the array into frequency mappings
        unordered_map<int,int> freq;
        for(int i = 0; i < nums.size(); ++i)  
            freq[nums[i]] += 1;
        // Step 2: maintain a min heap using frequency mappings
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        for(auto it : freq) {
            minHeap.push({it.second, it.first});
            if(minHeap.size() > k)
                minHeap.pop();
        }
        // Step 3: return the elements present in the min heap
        vector<int> ans;
        while(minHeap.size()) {
            ans.emplace_back(minHeap.top().second);
            minHeap.pop();
        }
        return ans;
    }
};