class Solution {
public:
    
    int mctFromLeafValues(vector<int>& arr) {
        vector<int> adj[16];
        int left[arr.size()];
        int right[arr.size()];
        int ans = 0;
        
        for(int i = 0; i < arr.size(); i++) adj[arr[i]].emplace_back(i);
        for(int i = 0; i < arr.size(); i++) left[i] = i - 1;
        for(int i = 0; i < arr.size(); i++) right[i] = i + 1;
        
        for(int i = 1; i <= 15; i++) {
            for(int j = 0; j < adj[i].size(); j++){
                int id = adj[i][j]; // index id in our array arr, global minimum
                int next_greater = 0; // minimum element between their neighbor (first check if they are valid)
                
                if(left[id] == -1 && right[id] != arr.size()) {
                    next_greater = arr[right[id]];
                } else if(left[id] != -1 && right[id] == arr.size()) {
                    next_greater = arr[left[id]];
                } else if(left[id] != -1 && right[id] != arr.size()) {
                    next_greater = min(arr[left[id]], arr[right[id]]);
                }
                
				//delete index id in our Linked list
                if(right[id] != arr.size()) left[right[id]] = left[id];
                if(left[id] != -1) right[left[id]] = right[id];
					
                ans += next_greater * i;
            }
        }
        return ans;
    }
};