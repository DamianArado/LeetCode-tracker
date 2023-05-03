class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_set<int> s1(begin(nums1), end(nums1)), s2(begin(nums2), end(nums2));
        for(const int &val : s1) 
            if(s2.count(val))
                ans.emplace_back(val);
        return ans;
    }
};