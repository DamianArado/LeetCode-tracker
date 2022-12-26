class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        // Step 1: calculate the indegree of each node
        vector<pair<int, int>> inDegree(n);
        for(auto &road : roads) {
            inDegree[road[0]].first = road[0], inDegree[road[0]].second += 1;
            inDegree[road[1]].first = road[1], inDegree[road[1]].second += 1;
        }
        // making sure it is not marked as zero in case of less roads
        for(int i = 0; i < n; ++i) 
            if(inDegree[i].first == 0) inDegree[i].first = i;
        // Step 2: sort on the basis of non-increasing in-degree of nodes
        sort(inDegree.begin(), inDegree.end(), [&] (auto x, auto y) {
            return x.second > y.second;
        });
        // Step 3: Assign nos. from n to 1 optimally now
        vector<pair<int, int>> assgnNo(n);
        for(int i = n; i >= 1; --i) {
            assgnNo[n - i].first = inDegree[n - i].first;
            assgnNo[n - i].second = i;
        }
        // Step 4: Calculate the total importance of the roads
        sort(assgnNo.begin(), assgnNo.end(), [&] (auto x, auto y) {
            return x.first < y.first;
        });
        long long importance = 0;
        for(auto &road : roads) {
            importance += (assgnNo[road[0]].second + assgnNo[road[1]].second);
        }
        return importance;
    }
};