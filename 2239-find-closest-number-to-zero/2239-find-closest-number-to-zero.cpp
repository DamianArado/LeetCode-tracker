class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int ans = INT_MAX;
        for(int &num : nums) {
            if(num == 0) return 0;
            else if(abs(num) < abs(ans)) ans = num;
            else if(abs(num) == abs(ans)) ans = max(num, ans);
        }
        return ans;
    }
};