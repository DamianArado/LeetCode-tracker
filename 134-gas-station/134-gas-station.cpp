class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int startIdx = 0, gasLeft = 0, totalGasLeft = 0, c = 0, s = 0;
        for(int i = 0; i < gas.size(); ++i) {
            s += gas[i], c += cost[i];
        }
        if(c > s) return -1;
        for(int i = 0; i < gas.size(); ++i) {
            gasLeft += gas[i] - cost[i];
            totalGasLeft += gas[i] - cost[i];
            if(gasLeft < 0) {
                // if we ran out of gas at i-th station, we cannot complete a circular route
                // we should again start at the next i-th position
                gasLeft = 0; 
                startIdx = i + 1;
            }
        }
        // if -ve that means total cost was greater than total gas
        // implying we couldn't complete a circular route
        return startIdx;
    }
};