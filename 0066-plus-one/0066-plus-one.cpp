class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int k = 1;
        for(int i = size(digits) - 1; i >= 0 and k > 0; --i) {
            digits[i] += k;
            k = digits[i] / 10;
            digits[i] %= 10;
        }
        if(k > 0) digits.insert(begin(digits), k);
        return digits;
    }
};