class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        // creating the variables required 
        int len = nums.size();
        int prod = nums[len-1];
        
        vector<int> answer(len);
        
        // edge case
        if(!len) return answer;
        
        // initialize answer and use it for the first pass
        answer[0] = 1;
        
        // each cell will be the product of previous and matching previous value in nums
        for(int i = 1; i<len; i++)
            answer[i] = answer[i-1]*nums[i-1];
        
        // second pass would be from right
        for(int i = --len-1; i>=0; --i) {
            answer[i] *= prod;
            prod *= nums[i];
        }
        
        return answer;
    }
};