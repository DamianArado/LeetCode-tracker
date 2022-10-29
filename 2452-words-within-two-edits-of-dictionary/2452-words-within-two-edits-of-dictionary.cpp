class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        int n = queries[0].size();
        
        for(string &query : queries) {
            for(string &dict : dictionary) {
                int count = 0;
                for(int i = 0; i < n; ++i) {
                    if(query[i] != dict[i]) 
                        ++count;
                }
                if(count <= 2) {
                    ans.emplace_back(query);
                    break;
                }
            }
        }
        return ans;
    }
};