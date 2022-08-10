typedef pair<int, int> pii;
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == k) return nums;
        priority_queue<pii, vector<pii>, greater<pii>> minHeapTemp;
        vector<int> maxSub;
        // Step 1: finding candidates for our subsequence - candidate: [element, element index]
        for(int i = 0; i < n; ++i) {
            minHeapTemp.push({ nums[i], i });
            if(minHeapTemp.size() > k) minHeapTemp.pop();
        }
        // Step 2: in another minHeap add all the candidates so that they are sorted wrt indices
        priority_queue<pii, vector<pii>, greater<pii>> minHeap;
        while(!minHeapTemp.empty()) {
            minHeap.push({ minHeapTemp.top().second, minHeapTemp.top().first });
            minHeapTemp.pop();
        }
        // Step 3: add candidates to our answer
        while(!minHeap.empty()) {
            maxSub.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return maxSub;
    }
};