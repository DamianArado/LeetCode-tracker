class Solution {
public:
    int minOperations(vector<int>& nums) {
        int operations = 0, last = 0;
        for (const auto &num : nums) {
            if (last - num + 1 > 0)
                operations += (last - num + 1);
            last = max(num, last + 1);
        }
        return operations;
    }
};