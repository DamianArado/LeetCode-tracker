class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        // [1, 3, 2]: 1- nums[i], 3: stack, 2: last
        int last = INT_MIN;
        stack<int> s;
        for (int i = size(nums) - 1; i >= 0; --i) {
            // checking if it's the smallest
            if (nums[i] < last)
                return true;
            // insert the bigger one in stack and maintain the smaller as last
            while (!s.empty() and nums[i] > s.top()) 
                last = s.top(), s.pop();
            s.emplace(nums[i]);
        }
        return false;
    }
};