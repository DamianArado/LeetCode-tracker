typedef pair<int, int> pii;

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        // create the adjacency list
        vector<vector<pii>> adjList(n);
        for(int i = 0; i < manager.size(); ++i) {
            if(i == headID) continue;
            adjList[manager[i]].emplace_back(i, informTime[i]);
        }
        // prepare the ds required for dijkstra's algorithm
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> times(n, INT_MAX);
        pq.emplace(informTime[headID], headID);
        times[headID] = informTime[headID];
        // run the algorithm
        while(!pq.empty()) {
            int time = pq.top().first, node = pq.top().second;
            pq.pop();
            for(auto &adjNode : adjList[node]) {
                int nextNode = adjNode.first, nextTime = adjNode.second;
                if(times[nextNode] > times[node] + nextTime) {
                    times[nextNode] = times[node] + nextTime;
                    pq.emplace(times[nextNode], nextNode);
                }
            }
        }
        // return the max distance (TIME)
        return *max_element(times.begin(), times.end());
    }
};