class Solution {
public:
    // bits in a beautiful subarray must appear couple of times
    // so their XOR must be zero
    // try to find all subarrays whose XOR is zero
    // hence we just used the logic to count subarrays with specific XOR
    long long beautifulSubarrays(vector<int>& nums) {
        unordered_map<int, int> prefixXOR{{0, 1}};
        long long ans = 0;
        for(int i = 0, currXOR = 0; i < size(nums); ++i) {
            currXOR ^= nums[i];
            if(prefixXOR.count(currXOR)) ans += prefixXOR[currXOR];
            prefixXOR[currXOR]++;
        }
        return ans;
    }
};