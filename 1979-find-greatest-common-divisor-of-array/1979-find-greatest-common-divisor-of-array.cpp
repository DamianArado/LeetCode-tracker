class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maxNum = *max_element(nums.begin(), nums.end());
        int minNum = *min_element(nums.begin(), nums.end());
        return __gcd(maxNum, minNum);
    }
};