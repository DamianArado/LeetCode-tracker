class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        // edge case
        if (size(intervals) == 0) {
            result.emplace_back(newInterval);
            return result;
        }
        // to keep a track of the intervals' indices so as to add the correct intervals in result
        int index = 0;
        // check if there is any independent interval before the newInterval
        while (index < intervals.size() and intervals[index][1] < newInterval[0])
            result.emplace_back(intervals[index++]);
        // checking for overlapping between intervals : check if the start of intervals <= end of newInterval
        while (index < intervals.size() and intervals[index][0] <= newInterval[1]) {
            // now we'll change the newInterval according to the number of overlapped intervals with min and max of the overlapped intervals
            newInterval[0] = min(intervals[index][0], newInterval[0]);
            newInterval[1] = max(intervals[index][1], newInterval[1]);
            // move on to check the next index in intervals
            index++;
        }
        // push this overlapped interval in our resultant
        result.emplace_back(newInterval);
        // check if we have some elements more after newInterval region, adding them straightaway
        while (index < intervals.size())
            result.emplace_back(intervals[index++]);
        return result;
    }
};