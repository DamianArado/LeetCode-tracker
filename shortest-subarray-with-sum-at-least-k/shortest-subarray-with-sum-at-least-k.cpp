class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long int> prefix_sum(n + 1, 0);
        for(int i = 0; i < n; ++i){
            prefix_sum[i + 1] = prefix_sum[i] + nums[i];
        }
        
        deque<int> dq;
        int res = n + 1;
        
        for(int i = 0; i < n + 1; ++i){
            // considering i as a potential END pointer
            while(!dq.empty() && prefix_sum[i] - prefix_sum[dq.front()] >= k){
                res = min(res, i - dq.front());
                dq.pop_front();
            }
            // evaluating i as a potential START pointer against other potential earlier START pointers. 
            // So if the start pointer before i has a larger sum, then it i will be the better choice.
            while(!dq.empty() && prefix_sum[i] <= prefix_sum[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return res = res > n ? -1 : res;
    }
};