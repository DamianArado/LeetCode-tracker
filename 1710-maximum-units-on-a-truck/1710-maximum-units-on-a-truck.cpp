class Solution {
public:
    static bool comparator(vector<int> &boxType1, vector<int> &boxType2) {
        return boxType1[1] >= boxType2[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        // here boxType[i][0] -> no. of box (weights), boxType[i][1] -> no. of units per box (values)
        // we can hence solve it like the fractional knapsack problem, here fraction would be the no. of boxes taken
        // sort boxTypes in the order of decreasing no. of units
        sort(boxTypes.begin(), boxTypes.end(), comparator);
        int maxTotalUnits = 0, currentBoxes = 0;
        for(int i = 0; i < boxTypes.size(); ++i) {
            if(currentBoxes + boxTypes[i][0] <= truckSize) {
                currentBoxes += boxTypes[i][0];
                maxTotalUnits += boxTypes[i][0] * boxTypes[i][1];
            } else {
                int remBoxesToAdd = truckSize - currentBoxes;
                currentBoxes += remBoxesToAdd;
                maxTotalUnits += boxTypes[i][1] * remBoxesToAdd;
                break;
            }
        }
        return maxTotalUnits;
    }
};