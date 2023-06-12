class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ranges;
        int n = size(nums);
        if (n == 0) return ranges;
        for (int i = 0; i < n; ++i) {
            int start = nums[i];
            while (i + 1 < n and nums[i] + 1 == nums[i + 1]) ++i;
            if (start != nums[i]) ranges.push_back(to_string(start) + "->" + to_string(nums[i]));
            else ranges.push_back(to_string(start));
        }
        return ranges;
    }
};