class Solution {
public:
    int arraySign(vector<int>& nums) {
        double product = 1;
        for(const int &num : nums) 
            product *= (num != 0 ? (num > 0 ? 1 : -1) : 0);
        if(product == 0) return 0;
        else if(product < 0) return -1;
        return 1;
    }
};