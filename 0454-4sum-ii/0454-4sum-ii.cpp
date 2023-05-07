class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> mp;
        for(const int &num1 : nums1) 
            for(const int &num2 : nums2)
                mp[num1 + num2]++;
        int ans = 0;
        for(const int &num3 : nums3)
            for(const int &num4 : nums4)
                ans += mp[-(num3 + num4)];
        return ans;
    }
};