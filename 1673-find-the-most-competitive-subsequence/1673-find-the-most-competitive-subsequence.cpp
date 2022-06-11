class Solution {
public:
    // TC - O(N), SC - O(k)
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        // here we will use a monotonically increasing stack
        vector<int> stack;
        // just one pass required
        for(int i = 0; i < nums.size(); ++i) {
            // the essential condition in order to pop an element from back of stack
            // elements after popping in stack: stack.size() - 1
            // elements that can be added to stack: nums.size() - i
            // at any instant max no. of elements in stack: k
            while(!stack.empty() and nums[i] < stack.back() and 
                  (stack.size() - 1 + nums.size() - i >= k))
                stack.pop_back();
            // if we can still add
            if(stack.size() < k)
                stack.push_back(nums[i]);
        }
        // returns the most competitive subsequence
        return stack;
    }
};