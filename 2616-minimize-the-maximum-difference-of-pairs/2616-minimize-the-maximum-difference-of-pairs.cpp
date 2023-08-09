class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(begin(nums), end(nums));
        int n = size(nums), left = 0, right = nums[n - 1] - nums[0];
        while (left < right) {
            int mid = left + (right - left) / 2, cnt = 0;
            for (int i = 1; i < n and cnt < p; ++i)
                if (nums[i] - nums[i - 1] <= mid)
                    ++cnt, ++i;
            if (cnt >= p) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};