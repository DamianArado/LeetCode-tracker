typedef pair<int, pair<int, int>> pip;
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // Step 1: create a min heap of type: [sum, [idx1, idx2]]
        priority_queue<pip, vector<pip>, greater<pip>> minHeap;
        // as a start, adding pairs using idx1 = 0 from nums1 and all the other elements inside nums2
        for(int i = 0; i < size(nums2); ++i)
            minHeap.push({nums1[0] + nums2[i], {0, i}});
        // Step 2: now create our array by adding only the min sum pairs
        vector<vector<int>> ans;
        while(!minHeap.empty() and k--) {
            auto top = minHeap.top(); 
            minHeap.pop();
            int x = top.second.first, y = top.second.second;
            ans.push_back({nums1[x], nums2[y]});
            if(x != size(nums1) - 1) minHeap.push({nums1[x + 1] + nums2[y], {x + 1, y}});
        }
        return ans;
    }
};