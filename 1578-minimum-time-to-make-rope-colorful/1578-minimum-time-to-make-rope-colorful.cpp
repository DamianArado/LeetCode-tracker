class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int minTime = 0, recurringMax = 0;
        for(int i = 0; i < colors.size(); ++i) {
            // if we don't see further repetitions
            if(i > 0 && colors[i] != colors[i - 1])
                recurringMax = 0;
            // add the minTime as min of the 2 being repeated
            minTime += min(recurringMax, neededTime[i]);
            // this will help us in the next iteration
            recurringMax = max(recurringMax, neededTime[i]);
        }
        return minTime;
    }
};