class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        if(grid[0][1] > 1 and grid[1][0] > 1) return -1;
        int m = size(grid), n = size(grid[0]);
        vector<vector<int>> dirs( { {1, 0}, {-1, 0}, {0, 1}, {0, -1} } );
        vector<vector<bool>> visited(m, vector<bool> (n));
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});  
        while(!pq.empty()) {
            int time = pq.top()[0], row = pq.top()[1], col = pq.top()[2];
            pq.pop();
            if(row == m - 1 and col == n - 1) return time;
            if(visited[row][col]) continue;
            visited[row][col] = true;
            for(const auto &dir : dirs) {
                int r = row + dir[0], c = col + dir[1];
                if(r == -1 or r == m or c == -1 or c == n or visited[r][c]) continue;
                int wait = (grid[r][c] - time) % 2 == 0;
                pq.push({max(time + 1, grid[r][c] + wait), r, c});
            }
        }
        return -1;
    }
};