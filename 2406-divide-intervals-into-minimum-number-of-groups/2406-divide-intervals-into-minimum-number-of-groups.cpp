class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> start, end;
        for(auto &interval : intervals) {
            start.emplace_back(interval[0]);
            end.emplace_back(interval[1]);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        
        int currentGRP = 1, minGRP = 1, i = 1, j = 0;
        while(i < n and j < n) {
            if(start[i] <= end[j]) {
                currentGRP += 1;
                i++;
            } else if(end[j] < start[i]) {
                currentGRP -= 1;
                j++;
            }
            minGRP = max(minGRP, currentGRP);
        }
        return minGRP;
    }
};