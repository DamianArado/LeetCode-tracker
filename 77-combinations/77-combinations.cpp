class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> result;
		int i = 0;
		vector<int> nums(k, 0); // vector of length k, all 0s
		while (i >= 0) {
            // Increment element at index i
			nums[i]++;  
            // Move index to the left if the element at index i has exceeded n
			if (nums[i] > n) --i;  
            
            /* 
             * If the index is at the end of the vector c, then (because the other conditions are
             * obeyed), we know we have a valid combination, so push it to our ans vector<vector<>>
             */
			else if (i == k - 1) result.emplace_back(nums);
            
            /* 
             * Move index to the right and set the element at that index equal to the element at the previous index.
             * Because of the increment at the beginning of this while loop, we ensure that the element at this index will be at least
             * one more than its neighbor to the left.
             */
			else {
			    ++i;
			    nums[i] = nums[i - 1];
			}
		}
		return result;
	}
};