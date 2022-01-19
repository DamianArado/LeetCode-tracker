class Solution {
private:
    int mergeSort(vector<int> &nums, int left, int right) {
        if(left >= right) return 0;
        int mid = left + (right - left) / 2;
        int invCnt = mergeSort(nums, left, mid);
        invCnt += mergeSort(nums, mid + 1, right);
        invCnt += merge(nums, left, mid, right);
        return invCnt;
    }
    int merge(vector<int> &nums, int left, int mid, int right) {
        int invCnt = 0, j = mid + 1;
        for(int i = left; i <= mid; ++i) {
            while(j <= right && nums[i] > 2LL*nums[j]) ++j;  // these increments determine how much we move j towards right from mid + 1, which is indeed our inversion count for that i 
            invCnt += (j - (mid + 1));  // counting inversions before doing the merge
        }
        vector<int> temp;
        // a -> left subarray & b -> right subarray
        int a = left, b = mid + 1;
        while(a <= mid && b <= right) {
            if(nums[a] < nums[b]) temp.emplace_back(nums[a++]);
            else temp.emplace_back(nums[b++]);
        }
        while(a <= mid) temp.emplace_back(nums[a++]);
        while(b <= right) temp.emplace_back(nums[b++]);
        for(int i = left; i <= right; ++i) nums[i] = temp[i - left];
        return invCnt;
    }
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};