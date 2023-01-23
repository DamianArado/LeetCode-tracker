class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.empty()) return n == 1 ? 1 : -1;
        vector<int> balance(n + 1);
        for(auto &t : trust) 
            --balance[t[0]], ++balance[t[1]];
        for(int i = 0; i <= n; ++i)
            if(balance[i] == n - 1)
                return i;
        return -1;
    }
};