class Solution {
    public int minCost(String colors, int[] neededTime) {
        int minTime = 0, recurringMax = 0;
        for(int i = 0; i < colors.length(); ++i) {
            // if we don't see further repetitions
            if(i > 0 && colors.charAt(i) != colors.charAt(i - 1))
                recurringMax = 0;
            // add the minTime as min of the 2 being repeated
            minTime += Math.min(recurringMax, neededTime[i]);
            // this will help us in the next iteration
            recurringMax = Math.max(recurringMax, neededTime[i]);
        }
        return minTime;
    }
}