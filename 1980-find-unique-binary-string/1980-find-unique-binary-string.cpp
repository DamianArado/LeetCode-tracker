class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans;
        // Cantor's Diagonal Argument
        for (int i = 0; i < size(nums); ++i)
            ans += nums[i][i] == '0' ? '1' : '0';
        return ans;
    }
};