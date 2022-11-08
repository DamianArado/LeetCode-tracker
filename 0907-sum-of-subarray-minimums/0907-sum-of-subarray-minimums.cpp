class Solution {
public:
    /***
    Doing this in O(n) should make it a hard problem.
    It took a while to understand the strategy.
    STEPS
    
    1. Insert a 0 at the front of vector and inside the stack.
    2. Use a monotonically increasing (non-decreasing) stack.
    3. Previous Less element for the first element is 0
    4. j will track the previous less element
    5. i will track the current subarray minimum: res[j] + (i - j) * nums[i]
       (i - j) will be the no. of times i dominates the min inside subarray
       res[j] makes sure we reuse the sum calculated till the previous less element's index
       
    */
    int sumSubarrayMins(vector<int>& arr) {
        
        arr.insert(begin(arr), 0);
        
        int n = size(arr), mod = 1e9 + 7, sum = 0;
        vector<int> res(n);
        stack<int> s;
        s.emplace(0);
        
        for(int i = 0; i < n; ++i) {
            while(!s.empty() and arr[s.top()] > arr[i])
                s.pop();
            int j = s.top();
            res[i] = res[j] + (i - j) * arr[i];
            s.emplace(i);
        }
        
        for(int i = 0; i < n; ++i)
            sum = (sum + res[i]) % mod;
        
        return sum;
    }
};