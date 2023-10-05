class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1 = -1, num2 = -1, count1 = 0, count2 = 0;
        for (const int &num : nums) {
            if (num == num1)
                ++count1;
            else if (num == num2)
                ++count2;
            else if (count1 == 0) 
                count1 = 1, num1 = num;
            else if (count2 == 0) 
                count2 = 1, num2 = num;
            else 
                --count1, --count2;
        }
        vector<int> ans;
        count1 = 0, count2 = 0;
        int n = size(nums);
        for (int i = 0; i < n; ++i) {
            if (nums[i] == num1) ++count1;
            else if (nums[i] == num2) ++count2;
        }
        if (count1 > n / 3) 
            ans.emplace_back(num1);
        if (count2 > n / 3) 
            ans.emplace_back(num2);
        return ans;
    }
};