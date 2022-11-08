class Solution {
public:
    // doing this in O(n) should make it a hard problem 
    // took a while to understand the strategy 
    /***
    
    
    
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