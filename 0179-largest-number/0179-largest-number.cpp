class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(begin(nums), end(nums), [&] (int x, int y) {
            return to_string(x) + to_string(y) > to_string(y) + to_string(x);
        });
        string ans;
        for(int i = 0; i < size(nums); ++i)
            ans += to_string(nums[i]);
        return ans[0] == '0' ? "0" : ans;
    }
};