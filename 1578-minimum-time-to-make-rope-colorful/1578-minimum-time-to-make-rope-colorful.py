class Solution(object):
    def minCost(self, colors, neededTime):
        """
        :type colors: str
        :type neededTime: List[int]
        :rtype: int
        """
        minTime = recurringMax = 0
        for i in range(len(colors)):
            if i > 0 and colors[i] != colors[i - 1]:
                recurringMax = 0
            minTime += min(recurringMax, neededTime[i])
            recurringMax = max(recurringMax, neededTime[i])
        return minTime
        