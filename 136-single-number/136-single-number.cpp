class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int singleBoy = 0;
        for(int num : nums) singleBoy ^= num;
        return singleBoy;
    }
};