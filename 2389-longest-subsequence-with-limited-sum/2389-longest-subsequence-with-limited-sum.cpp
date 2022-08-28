class Solution {
private:
    int findIdx(vector<int> &prefixSum, int query) {
        int start = 0, end = size(prefixSum) - 1, ans = -1; 
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if(prefixSum[mid] <= query) {
                ans = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ans;
    }
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size(), m = queries.size(), sum = 0;
        vector<int> prefixSum;
        // Step 1: Sort the nums array and store the prefix sum
        sort(nums.begin(), nums.end());
        for(int &num : nums) {
            sum += num;
            prefixSum.emplace_back(sum);
        }
        // Step 2: For each query[i], find the last element in prefixSum such that prefixSum[j] <= query[i]
        // using binary search
        vector<int> ans;
        for(int &query : queries) {
            int idx = findIdx(prefixSum, query);
            ans.emplace_back(idx + 1);
        }
        return ans;
    }
};