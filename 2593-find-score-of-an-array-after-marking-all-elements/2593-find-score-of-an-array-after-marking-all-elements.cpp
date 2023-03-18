typedef pair<int, int> pii;
class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long score = 0;
        int n = size(nums);
        priority_queue<pii, vector<pii>, greater<>> minHeap;
        for(int i = 0; i < n; ++i)
            minHeap.emplace(nums[i], i);
        vector<bool> visited(n);
        while(!minHeap.empty()) {
            auto [elem, idx] = minHeap.top();
            minHeap.pop();
            if(visited[idx]) continue;
            score += elem;
            visited[idx] = true;
            if(idx > 0 and !visited[idx - 1]) visited[idx - 1] = true;
            if(idx < n - 1 and !visited[idx + 1]) visited[idx + 1] = true;
        }
        return score;
    }
};