class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        // same as max performance of a team
        int n = size(nums1);
        if(n == 1) return nums1[0] * nums2[0];
        vector<pair<int, int>> numbers;
        for(int i = 0; i < n; ++i)
            numbers.emplace_back(nums2[i], nums1[i]);
        sort(begin(numbers), end(numbers));
        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long sum = 0, score = 0;
        for(int i = n - 1; i >= 0; --i) {
            sum += numbers[i].second;
            minHeap.emplace(numbers[i].second);
            if(size(minHeap) > k) {
                sum -= minHeap.top();
                minHeap.pop();
            }
            if(size(minHeap) == k) 
                score = max(score, sum * numbers[i].first);
        }
        return score;
    }
};