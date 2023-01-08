class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int cntPlus = 0, cntNeg = 0;
        for(int &num : nums) {
            if(num < 0) cntNeg++;
            else if(num > 0) cntPlus++;
        }
        return max(cntPlus, cntNeg);
    }
};