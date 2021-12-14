class Solution {
public:
    bool canSplit(int upperBoundSubarraySum, vector<int>& nums, int m) {
        int curSubarraySum = 0, cntSubarray = 1;
        
        for (int num : nums) {
            curSubarraySum += num;
            if (curSubarraySum > upperBoundSubarraySum) {
                cntSubarray++;
                curSubarraySum = num;
                if (cntSubarray > m) {
                    return false;
                }
            }
        }

        return true;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int minVal = INT_MIN, maxVal = 0;
        for (int num : nums) {
            minVal = max(minVal, num);
            maxVal += num;
        }

        while (minVal < maxVal) {
            int mid = minVal + (maxVal - minVal) / 2;
            if (canSplit(mid, nums, m)) {
                maxVal = mid;
            } else {
                minVal = mid + 1;
            }
        }

        return minVal;
    }
};