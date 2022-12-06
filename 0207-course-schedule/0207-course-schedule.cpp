class Solution {
private:
    bool isCycleDFS(int current, vector<int> adjList[], vector<bool> &visited, vector<bool> &dfsVisit) {
        visited[current] = dfsVisit[current] = true;
        for(int &adjNode : adjList[current]) {
            if(!visited[adjNode] and isCycleDFS(adjNode, adjList, visited, dfsVisit))
                return true;
            else if(dfsVisit[adjNode]) 
                return true;
        }
        dfsVisit[current] = false;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // We cannot finish all courses if we found a cycle in our graph
        // for that let's first create our graph
        vector<int> adjList[numCourses];
        vector<bool> visited(numCourses), dfsVisit(numCourses);
        for(auto &prereq : prerequisites)
            adjList[prereq[0]].push_back(prereq[1]);
        // Lets use DFS to check whether or not there exists a cycle in our graph
        for(int i = 0; i < numCourses; ++i) {
            if(!visited[i] and isCycleDFS(i, adjList, visited, dfsVisit))
                return false;
        }
        return true;
    }
};