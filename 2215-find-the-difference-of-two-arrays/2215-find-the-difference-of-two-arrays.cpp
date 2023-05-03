class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans(2);
        unordered_set<int> s1(begin(nums1), end(nums1)), s2(begin(nums2), end(nums2));
        for(const int &val : s1) 
            if(!s2.count(val))
                ans[0].emplace_back(val);
        for(const int &val : s2) 
            if(!s1.count(val))
                ans[1].emplace_back(val);
        return ans;
    }
};