/**


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


*/

class Solution {
    // using my fav DFS
public:
    bool canReach(vector<int>& arr, int start) {
        if(start < 0 or start >= size(arr) or arr[start] < 0) return false;
        if(arr[start] == 0) return true;
        arr[start] = -arr[start];
        return canReach(arr, start - arr[start]) or canReach(arr, start + arr[start]);
    }
};