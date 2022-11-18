class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int second = INT_MIN;
        stack<int> s; // using a monotonically increasing stack
        for(int i = size(nums) - 1; i >= 0; --i) {
            // taking care of 1 in our pattern
            if(nums[i] < second) return true;
            // taking care of the 32 in our pattern
            while(!s.empty() and nums[i] > s.top()) {
                second = s.top();
                s.pop();
            }
            s.emplace(nums[i]);
        }
        return false;
    }
};