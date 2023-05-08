// TC - O(nlogk), SC - O(k)
typedef pair<int, int> pii;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: covert the array into frequency mappings
        unordered_map<int,int> freqMap;
        for(const int &num : nums)  
            freqMap[num]++;
        // Step 2: maintain a min heap using frequency mappings
        priority_queue<pii, vector<pii>, greater<pii>> minHeap;
        for(const auto &[element, freq] : freqMap) {
            minHeap.emplace(freq, element);
            if(minHeap.size() > k)
                minHeap.pop();
        }
        // Step 3: return the elements present in the min heap
        vector<int> ans;
        while(!minHeap.empty()) {
            ans.emplace_back(minHeap.top().second);
            minHeap.pop();
        }
        return ans;
    }
};