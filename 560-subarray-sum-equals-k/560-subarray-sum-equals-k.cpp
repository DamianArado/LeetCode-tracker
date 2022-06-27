/**

Approach 1: Using prefix sum

int subarraySum(vector<int>& nums, int k) {
        int count = 0, n = nums.size() + 1;
        vector<int> prefixSum(n, 0);
        // build the prefix sum array
        for(int i = 1; i < n; ++i)
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        // iterate using 2 loops over the prefix sum array and find k 
        for(int start = 0; start < n; ++start)
            for(int end = start + 1; end < n; ++end)
                if(prefixSum[end] - prefixSum[start] == k)
                    count++;
        return count;
    }
    
TC: O(n^2), SC: O(n)  [TLE]

Approach 2: Using prefix sum and unordered map

TC and SC: O(n)

*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0, prefixSum = 0;
        unordered_map<int,int> sumFreq;
        sumFreq[0] = 1;
        for(int num : nums) {
            prefixSum += num;
            int target = prefixSum - k;
            // check if we already have target inside the map or not
            if(sumFreq.find(target) != sumFreq.end())
                // add the frequency of its occurrence to the answer
                ans += sumFreq[target];
            // add frequency of this new cumulative sum inside the map
            sumFreq[prefixSum]++;
        }
        return ans;
    }
};