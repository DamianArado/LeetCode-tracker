class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int> mp;
        for(auto &trip : trips)
            mp[trip[1]] += trip[0], mp[trip[2]] -= trip[0];
        for(auto &key : mp)
            if((capacity -= key.second) < 0) return false;
        return true;
    }
};