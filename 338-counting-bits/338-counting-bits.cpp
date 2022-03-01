class Solution {
public:
    vector<int> countBits(int num) 
    {
        vector<int> v(num + 1, 0);
        // when you multiply a number by 2, you simply shift all the bits to the left. 
        // If it's even, you're done, if it's odd, you add 1 more.
        for(int i = 1; i <=  num; i++) 
            v[i] = v[i / 2] + i % 2;
        return v;
    }
};