class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = size(nums);
        if(n == 1) return {-1};
        
        stack<pair<int, int>> s;
        s.emplace(nums[0], 0);
        int x = nums[1];
        vector<int> ans(n);
        
        for(int i = 1; i < n; ++i) {
            x = nums[i];
            if(x <= s.top().first) s.emplace(x, i);
            else {
                while(!s.empty() and x > s.top().first) {
                    ans[s.top().second] = x;
                    s.pop();
                }
                s.emplace(x, i);
            }
        }
        
        for(int i = 0; i < n; ++i) {
            x = nums[i];
            while(x > s.top().first) {
                ans[s.top().second] = x;
                s.pop();
            }
        }
        while(!s.empty()) {
            ans[s.top().second] = -1;
            s.pop();
        }
        return ans;
    }
};