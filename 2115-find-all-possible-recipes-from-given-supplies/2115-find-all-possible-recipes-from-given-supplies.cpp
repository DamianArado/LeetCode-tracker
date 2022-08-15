class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<string>> graph;
        unordered_set<string> s(supplies.begin(), supplies.end());
        
        // to store the indegrees of all the recipes
        unordered_map<string, int> inDegree;
        for(auto x : recipes) inDegree[x] = 0;
        
        for(int i = 0; i < recipes.size(); ++i) {
            for(int j = 0; j < ingredients[i].size(); ++j) {
                if(s.find(ingredients[i][j]) == s.end()) {
                    // if the ingredient required to make a recipe is not in the supplies then we need 
                    // to make a directed edge from that ingredient to recipe
                    graph[ingredients[i][j]].push_back(recipes[i]);
                    inDegree[recipes[i]]++;
                }
            }
        }
        
        // Kahn's algo
        queue<string> q;
        for(auto it : inDegree) 
            if(it.second == 0) 
                q.push(it.first);
        vector<string> ans;
        while(!q.empty()) {
            string current = q.front();
            q.pop();
            ans.push_back(current);
            for(auto it : graph[current]) {
                inDegree[it]--;
                if(inDegree[it] == 0)
                    q.push(it);
            }
        }
        
        return ans;
    }
};