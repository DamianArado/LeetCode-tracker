class Solution {
private:
    void merge(vector<int> &nums, int low, int mid, int high) {
        if(low >= high) return;
        int l = low, r = mid + 1, k = 0, size = high - low + 1;
        vector<int> sorted(size);
        while(l <= mid and r <= high)
            sorted[k++] = nums[l] < nums[r] ? nums[l++] : nums[r++];
        while(l <= mid) sorted[k++] = nums[l++];
        while(r <= high) sorted[k++] = nums[r++];
        for(k = 0; k < size; ++k) nums[low + k] = sorted[k];
    }
    void mergeSort(vector<int> &nums, int low, int high) {
        if(low >= high) return;
        int mid = low + (high - low) / 2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid + 1, high);
        merge(nums, low, mid, high);
    }
public:
    // merge sort - O(nlogn) time and O(n) space
    vector<int> sortArray(vector<int>& nums) {
        int low = 0, high = size(nums) - 1;
        mergeSort(nums, low, high);
        return nums;
    }
};