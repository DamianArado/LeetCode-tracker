class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = size(intervals);
        if(n == 1) return intervals;
        
        vector<vector<int>> mergedIntervals;
        sort(begin(intervals), end(intervals));
        int lastMin = intervals[0][0], lastMax = intervals[0][1];
        for(int i = 1; i < n; ++i) {
            int currMin = intervals[i][0], currMax = intervals[i][1];
            if(currMin > lastMax) { 
                mergedIntervals.push_back({lastMin, lastMax});
                lastMin = currMin, lastMax = currMax;
            }
            else lastMax = max(lastMax, currMax);
        } 
        mergedIntervals.push_back({lastMin, lastMax});
        return mergedIntervals;
    }
};