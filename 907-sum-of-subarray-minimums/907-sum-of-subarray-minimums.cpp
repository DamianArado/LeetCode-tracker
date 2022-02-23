class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int threshold = 1000000007;
        const int n = (int)arr.size();
        vector<int> prevLess (n, -1);
        vector<int> nextLess (n, n);
        vector<int> monoStack;
        for (int i=0; i<n; i++) {
            while(!monoStack.empty() && arr[monoStack.back()] > arr[i]) {
                nextLess[monoStack.back()] = i;
                monoStack.pop_back();
            }
            if (!monoStack.empty()) {
                prevLess[i] = monoStack.back();    
            }
            monoStack.push_back(i);
        }
        
        long sum = 0;
        for (int i=0; i<n; i++) {
            sum += (long)arr[i] * (i - prevLess[i]) * (nextLess[i] - i);
            if (sum > threshold) {
                sum -= threshold;
            }
        }
        return (int)sum;
    }
};