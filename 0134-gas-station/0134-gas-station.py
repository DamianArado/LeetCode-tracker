class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        startIdx = gasLeft = costSum = gasSum = 0
        for i in range (len(gas)):
            gasSum += gas[i]
            costSum += cost[i]
        # we cannnot complete a circular route
        if costSum > gasSum: return -1
        # we can complete a circular route, we just need to find the starting index
        for i in range (len(gas)):
            gasLeft += gas[i] - cost[i]
            if gasLeft < 0:
                # if we ran out of gas at i-th station, we cannot complete a circular route
                # we should again start at the next i-th position
                gasLeft = 0
                startIdx = i + 1
        return startIdx