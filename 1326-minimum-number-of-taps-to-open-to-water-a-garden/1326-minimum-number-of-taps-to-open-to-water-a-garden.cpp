class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int minTaps = 0;
        vector<pair<int,int>> waterRange;
        for(int i = 0; i <= n; ++i)
            waterRange.push_back({i - ranges[i], i + ranges[i]});
        sort(waterRange.begin(), waterRange.end(), [](pair<int,int> a, pair<int,int> b) {
           return a.second > b.second;
        });
        int start = n, end = n, idx = 0;
        while(end > 0) {
            while(idx < waterRange.size() and waterRange[idx].second >= end) {
                start = min(start, waterRange[idx].first);
                idx++;
            }
            if(start == end)
                return -1;
            end = start;
            minTaps++;
        }
        return minTaps;
    }
};