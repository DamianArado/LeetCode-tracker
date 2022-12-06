class Solution {
private:
    bool isCycleDFS(int start, vector<int> adjList[], vector<bool> &visited, 
                    vector<bool> &dfsVisit, stack<int> &courseDFS) {
        visited[start] = dfsVisit[start] = true;
        for(int &adjNode : adjList[start]) {
            if(!visited[adjNode] and isCycleDFS(adjNode, adjList, visited, dfsVisit, courseDFS))
                return true;
            else if(dfsVisit[adjNode])
                return true;
        }
        dfsVisit[start] = false;
        courseDFS.push(start);
        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // lets first create our graph using adjacency list representation
        vector<int> adjList[numCourses];
        for(auto &prereq : prerequisites)
            adjList[prereq[1]].emplace_back(prereq[0]);
        
        // now we will use DFS to iterate over our graph and check if we see a cycle
        // if we don't see a cycle we will return our answer
        vector<int> courseOrder;
        stack<int> courseDFS;
        vector<bool> visited(numCourses), dfsVisit(numCourses);
        
        for(int i = 0; i < numCourses; ++i) {
            if(!visited[i] and isCycleDFS(i, adjList, visited, dfsVisit, courseDFS))
                return {};
        }
        // now add the courses done from the stack into our answer
        while(!courseDFS.empty()) {
            courseOrder.push_back(courseDFS.top());
            courseDFS.pop();
        }
        return courseOrder;
    }
};