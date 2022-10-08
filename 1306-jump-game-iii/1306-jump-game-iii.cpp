class Solution {
    // using BFS
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q;
        q.emplace(start);
        while(!q.empty()) {
            int current = q.front(); q.pop();
            if(arr[current] == 0) return true;
            if(arr[current] < 0) continue;
            if(current + arr[current] < size(arr)) q.emplace(current + arr[current]);
            if(current - arr[current] >= 0) q.emplace(current - arr[current]);
            arr[current] = -arr[current];
        }
        return false;
    }
};