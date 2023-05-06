class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = size(intervals);
        if(n == 1) return intervals;
        vector<vector<int>> mergedIntervals;
        sort(begin(intervals), end(intervals));
        int start = intervals[0][0], end = intervals[0][1];
        for(int i = 1; i < n; ++i) {
            int next_start = intervals[i][0], next_end = intervals[i][1];
            if(next_start <= end) end = max(end, next_end);
            else {
                mergedIntervals.push_back({start, end});
                start = intervals[i][0], end = intervals[i][1];
            }
        }
        mergedIntervals.push_back({start, end});
        return mergedIntervals;
    }
};