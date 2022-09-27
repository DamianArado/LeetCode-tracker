class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int ans = 0, sum = 0;
        for(int &e : nums) {
            sum += e;
            ans = min(ans, sum);
        }
        return -ans + 1;
    }
};