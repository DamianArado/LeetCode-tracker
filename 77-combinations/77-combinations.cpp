class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
	vector<vector<int>> ans;
	int idx = 0;
	// generate a vector of size k containing all zeroes
	vector<int> nums(k, 0);
	while(idx >= 0) {
		// increase element at index
		++nums[idx];
		// if value at index increases beyond n, decrease index
		if(nums[idx] > n) --idx;
		// if index is equal to k, add to answer
		else if (idx == k - 1) ans.emplace_back(nums);
		// otherwise move index to right and make the element equal to its left one
		// this is because the element at right becomes greater than n
		else {
			++idx;
			nums[idx] = nums[idx - 1];
		}
	}
	return ans;
}
};