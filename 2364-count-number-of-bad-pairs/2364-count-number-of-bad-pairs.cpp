class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long valid = 0, n = size(nums);
        /**
        Total = valid + invalid
        Invalid pairs: j - i != nums[j] - nums[i] or j - nums[j] != i - nums[i]
        Total pairs: Nc2 = n * (n - 1) / 2
        Valid pairs = Total - Invalid
        
        The idea is to use a map and count all the invalid pairs. For each index j, we will see 
        if the difference j - nums[j] is seen earlier as well at some index i and we count all
        such occurences and add it to our invalid pairs.
        */
        unordered_map<int, int> mp;
        for(int i = 0; i < n; ++i)
            valid += mp[i - nums[i]]++;
        long long invalid = n * (n - 1) / 2 - valid;
        return invalid;
    }
};