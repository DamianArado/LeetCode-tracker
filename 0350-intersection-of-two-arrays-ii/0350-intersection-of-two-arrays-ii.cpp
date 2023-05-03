class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int, int> mp;
        for(const int &num1 : nums1)
            mp[num1]++;
        for(const int &num2 : nums2)
            if(mp.count(num2)) {
                ans.emplace_back(num2);
                if(--mp[num2] == 0) mp.erase(num2);
            }
        return ans;
    }
};