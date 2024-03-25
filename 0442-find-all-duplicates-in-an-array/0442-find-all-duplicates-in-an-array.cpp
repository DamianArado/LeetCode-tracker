class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // O(n) time and O(1) space involves modifying the input array
        vector<int> duplicates;
        for (int i = 0; i < size(nums); ++i) {
            int pos = abs(nums[i]) - 1;
            if (nums[pos] < 0)
                duplicates.emplace_back(pos + 1);
            else
                nums[pos] = -nums[pos];
        }
        return duplicates;
    }
};