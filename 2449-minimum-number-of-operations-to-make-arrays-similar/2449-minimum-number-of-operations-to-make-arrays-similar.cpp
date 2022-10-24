class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        // Step 1: Create two 2-d arrays to store odd and even numbers
        // values in nums will get stored in temp1: 0 - even, 1 - odd
        // values in target will get stored in temp2: 0 - even, 1 - odd
        vector<vector<int>> temp1(2), temp2(2);
        for(int &num : nums) temp1[num % 2].emplace_back(num);
        for(int &tgt: target) temp2[tgt % 2].emplace_back(tgt);
        
        // Step2: Sort the 2d arrays so that we can compare easily
        sort(begin(temp1[0]), end(temp1[0])); 
        sort(begin(temp1[1]), end(temp1[1]));
        sort(begin(temp2[0]), end(temp2[0]));
        sort(begin(temp2[1]), end(temp2[1]));
        
        // Step3: Compare and add the difference / 2 to our result as it is the min difference we can see
        // We don't divide by 4 here as the numbers below 4 will not be taken into account then
        long long ans = 0;
        for(int i = 0; i < size(temp1[0]); ++i)
            ans += (abs(temp1[0][i] - temp2[0][i]) / 2);
        for(int i = 0; i < size(temp1[1]); ++i)
            ans += (abs(temp1[1][i] - temp2[1][i]) / 2);
        
        // We divided by 2 so we need to divide again due to the 2nd operation
        return ans / 2;
    }
};