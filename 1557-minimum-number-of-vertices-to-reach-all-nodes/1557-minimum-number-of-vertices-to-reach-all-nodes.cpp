class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        vector<bool> isInDegree(n);
        for(const auto &e : edges) 
            isInDegree[e[1]] = true;
        for(int i = 0; i < n; ++i) 
            if(!isInDegree[i])
                ans.emplace_back(i);
        return ans;
    }
};