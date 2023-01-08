class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long score = 0;
        priority_queue<int> maxHeap(begin(nums), end(nums));
        while(k--) {
            long long current = maxHeap.top();
            maxHeap.pop();
            score += current;
            if(current % 3 == 0) maxHeap.emplace(current / 3);
            else maxHeap.emplace(current / 3 + 1);
        }
        return score;
    }
};