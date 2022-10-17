class Solution {
public:
    int triangularSum(vector<int>& nums) {
        vector<int> aux = nums;
        int n = size(aux);
        while(n > 1) {
            vector<int> newNums(n - 1);
            for(int i = 0; i < n - 1; ++i) 
                newNums[i] = (aux[i] + aux[i + 1]) % 10;
            aux = newNums;
            n -= 1;
        }
        return aux[0];
    }
};