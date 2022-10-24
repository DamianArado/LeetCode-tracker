class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = size(nums), missing = -1;
        vector<int> ans;
        unordered_map<int, int> mp;
        for(int i = 1; i <= n; ++i) mp[i]++;
        for(int &num : nums) mp[num]++;
        for(auto &it : mp) {
            if(it.second == 3) ans.emplace_back(it.first);
            else if(it.second == 1) missing = it.first;
        }
        ans.emplace_back(missing);
        return ans;
    }
};