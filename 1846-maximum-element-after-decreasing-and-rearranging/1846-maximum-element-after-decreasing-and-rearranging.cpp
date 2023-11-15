class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int maxElement = 1, n = size(arr);
        unordered_map<int, int> count;
        for (const int &num : arr)
            ++count[min(num, n)];
        // max element should not be greater than the number itself
        for (int num = 1; num <= n; ++num)
            maxElement = min(maxElement + count[num], num);
        return maxElement;
    }
};