class Solution {
public:
    // This deserved to be marked as HARD! Very difficult to come up with the intuition to solve this
    // better read the notes again and again to grasp the intuition behind why we did the steps given below
    // Best approach: https://www.nayuki.io/page/next-lexicographical-permutation-algorithm
    /**
    
    The high level steps to solve this beautiful problem using O(n) time and O(1) space
    
    1. Find the largest index i which will be the starting index of the suffix such that nums[i - 1] < nums[i]
    2. If there is no such i, reverse the complete array as it will be the last permutation
    3. Now, for i, make pivot = i - 1. nums[pivot] is smaller than nums[i].
    4. For this pivot, find the largest index j, such that j >= i and nums[j] > nums[pivot]
    5. Swap nums[j] and nums[pivot] for a minimal increase (lexicographically next larger sequence)
    6. Lastly, reverse the sequence from nums[i] to end of nums to get the required next permutation.
    */
    void nextPermutation(vector<int>& nums) {
        int n = size(nums);
        if(n == 1) return;
        
        int suffixStart = n - 1;
        while(suffixStart > 0 and nums[suffixStart - 1] >= nums[suffixStart])
            suffixStart--;
        if(suffixStart == 0 and nums[suffixStart] >= nums[suffixStart + 1]) reverse(begin(nums), end(nums));
        else {
            int pivot = suffixStart - 1;
            int rightMostGreater = n - 1;
            while(rightMostGreater >= suffixStart and nums[rightMostGreater] <= nums[pivot])
                rightMostGreater--;
            swap(nums[pivot], nums[rightMostGreater]);
            reverse(begin(nums) + suffixStart, end(nums));
        }
    }
};