class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        // events[0,1] -> events[i][0] = startTime[i], events[i][1] = endTime[i]
        // Step 1: Sort events act their startTime
        sort(events.begin(), events.end());
        // Step 2: initialize day as the startTime of the earliest occurring event
        // and see if we have any events that are starting the same day
        // if YES, add those inside a min heap (ending sooner on top)
        int day = 0, maxEvents = 0, n = events.size(), i = 0;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        while(!minHeap.empty() or i < n) {
            if(minHeap.empty())
                day = events[i][0];
            // keep condition for i before otherwise see runtime error
            while(i < n and events[i][0] <= day)
                minHeap.push(events[i++][1]);
            // Step 3: attend the event ending sooner on that day and move on to the next day
            minHeap.pop();
            ++day, ++maxEvents;
            // any event that happened in the past cannot be attended
            while(!minHeap.empty() and minHeap.top() < day)
                minHeap.pop();
        }
        return maxEvents;
    }
};