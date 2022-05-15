class Solution {
private:
    bool checkCycle(int start, vector<int> adjList[], vector<bool> &visited, vector<bool> &dfsCurrentVisit, vector<int> &ans) {
        // we visit the start vertex
        visited[start] = dfsCurrentVisit[start] = true;
        
        // for all nodes in the adjacency list of start vertex
        for(auto it : adjList[start]) {
            // if its not visited and we found a cycle
            if(!visited[it] && checkCycle(it, adjList, visited, dfsCurrentVisit, ans))
                return true;
            // if its visited in the current dfs call
            else if(dfsCurrentVisit[it])
                return true;
        }
        // adding start vertex to answer
        ans.push_back(start);
        // we will return from the current dfs call hence marking it as unvisited
        dfsCurrentVisit[start] = false;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites, vector<int> &ans) {
        // to label all vertices as visited or not
        vector<bool> visited(numCourses, false);
        // to label all vertices in the current dfs call as visited or not
        vector<bool> dfsCurrentVisit(numCourses, false);
        // array of vectors for adjacency list
        vector<int> adjList[numCourses];
        
        // constructing our adjacency list
        for(auto it : prerequisites) {
            adjList[it[0]].push_back(it[1]);
        }
        // checking all components for cycle
        for(int i = 0; i < numCourses; ++i) {
            // if we found a cycle we can't finish all courses
            if(!visited[i] && checkCycle(i, adjList, visited, dfsCurrentVisit, ans))
                return false;
        }
        // no cycle so we have an answer
        return true;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        if(numCourses == 1) return {0};
        if(canFinish(numCourses, prerequisites, ans))
            return ans;
        return {};
    }
};