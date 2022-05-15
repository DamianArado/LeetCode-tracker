class Solution {
private:
    bool checkCycle(int start, vector<int> adjList[], vector<bool> &visited, vector<bool> &dfsCurrentVisit, vector<int> &ans) {
        visited[start] = dfsCurrentVisit[start] = true;
        
        for(auto it : adjList[start]) {
            if(!visited[it] && checkCycle(it, adjList, visited, dfsCurrentVisit, ans))
                return true;
            else if(dfsCurrentVisit[it])
                return true;
        }
        ans.push_back(start);
        dfsCurrentVisit[start] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites, vector<int> &ans) {
        vector<bool> visited(numCourses, false);
        vector<bool> dfsCurrentVisit(numCourses, false);
        vector<int> adjList[numCourses];  // array of vectors
        
        for(auto it : prerequisites) {
            adjList[it[0]].push_back(it[1]);
        }
        for(int i = 0; i < numCourses; ++i) {
            if(!visited[i] && checkCycle(i, adjList, visited, dfsCurrentVisit, ans))
                return false;
        }
        return true;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        if(numCourses == 1) return {0};
        
        if(canFinish(numCourses, prerequisites, ans)) {
            return ans;
        }    
        return {};
    }
};