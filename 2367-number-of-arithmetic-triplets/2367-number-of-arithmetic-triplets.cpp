class Solution {
public:
    // Check if number - diff and number - 2 * diff occurred in nums
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int count[201] = {};
        int result = 0;
        for(int num : nums) {
            if(num >= 2 * diff)
                result += count[num - diff] and count[num - 2 * diff];
            count[num] = 1;
        }
        return result;
    }
};