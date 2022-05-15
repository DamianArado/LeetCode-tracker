class Solution {
private:
    bool checkCycle(int start, vector<int> adjList[], vector<bool> &visited, vector<bool> &dfsCurrentVisit) {
        visited[start] = dfsCurrentVisit[start] = true;
        
        for(auto it : adjList[start]) {
            if(!visited[it] && checkCycle(it, adjList, visited, dfsCurrentVisit))
                return true;
            else if(dfsCurrentVisit[it])
                return true;
        }
        
        dfsCurrentVisit[start] = false;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> visited(numCourses, false);
        vector<bool> dfsCurrentVisit(numCourses, false);
        vector<int> adjList[numCourses];  // array of vectors
        
        for(auto it : prerequisites) {
            adjList[it[0]].push_back(it[1]);
        }
        for(int i = 0; i < numCourses; ++i) {
            if(!visited[i] && checkCycle(i, adjList, visited, dfsCurrentVisit))
                return false;
        }
        return true;
    }
};