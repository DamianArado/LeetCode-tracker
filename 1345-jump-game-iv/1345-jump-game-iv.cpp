class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = size(arr);
        if(n == 1) return 0;
        // This approach uses BFS to process each index 
        // each index added to the queue is the possible next move
        // Step 1: build a map which will store indexes for each number
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; ++i)
            mp[arr[i]].emplace_back(i);
        queue<int> q;
        q.emplace(0);
        int jumps = 0;
        while(!q.empty()) {
            ++jumps;
            int sz = size(q);
            for(int i = 0; i < sz; ++i) {
                int current = q.front();
                q.pop();
                // check for i - 1
                if(current - 1 >= 0 and mp.count(arr[current - 1]))
                    q.emplace(current - 1);
                // check for i + 1
                if(current + 1 == n - 1) return jumps;
                if(current + 1 < n and mp.count(arr[current + 1]))
                    q.emplace(current + 1);
                // check for j, such that i != j and arr[i] == arr[j]
                if(mp.count(arr[current])) {
                    for(int &idx : mp[arr[current]]) {
                        if(idx != current) {
                            if(idx == n - 1) return jumps;
                            q.emplace(idx);
                        }
                    }
                }
                mp.erase(arr[current]);
            }
        }
        return jumps;
    }
};