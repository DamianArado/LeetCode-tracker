class Solution {
private:
    static bool comparator(vector<int> &a, vector<int> &b) {
        return a[1] < b[1];
    }
public:
    // tc - O(nlogn), sc - O(1)
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans = -1;
        // Step 1: Sort the intervals act their end times greedily
        sort(intervals.begin(), intervals.end(), comparator);
        // Step 2: Check if the current interval starts before the prevous one ends
        auto previous = intervals[0];
        for(auto current : intervals) {
            if(previous[1] > current[0]) ans++;
            else previous = current;
        }
        return ans;
    }
};