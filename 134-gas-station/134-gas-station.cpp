class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int startIdx = 0, gasLeft = 0, costSum = 0, gasSum = 0;
        for(int i = 0; i < gas.size(); ++i)
            gasSum += gas[i], costSum += cost[i];
        if(costSum > gasSum) return -1;
        // we can complete a circular route, we just need to find the starting index
        for(int i = 0; i < gas.size(); ++i) {
            gasLeft += gas[i] - cost[i];
            if(gasLeft < 0) {
                // if we ran out of gas at i-th station, we cannot complete a circular route
                // we should again start at the next i-th position
                gasLeft = 0; 
                startIdx = i + 1;
            }
        }
        return startIdx;
    }
};