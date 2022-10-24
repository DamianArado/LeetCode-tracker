/**

Solution 1: O(n) time & space

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

*/

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans(2);
        for(int &num : nums)
            if(nums[abs(num) - 1] < 0) ans[0] = abs(num);
            else nums[abs(num) - 1] *= -1;
        for(int i = 0; i < size(nums); ++i)
            if(nums[i] > 0)
                ans[1] = i + 1;
        return ans;
    }
};