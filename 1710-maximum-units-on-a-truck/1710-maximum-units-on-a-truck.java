class Solution {
    public int maximumUnits(int[][] boxTypes, int truckSize) {
        Arrays.sort(boxTypes, (a,b) -> b[1] - a[1]);
        int maxTotalUnits = 0, currentBoxes = 0;
        for(int i = 0; i < boxTypes.length; ++i) {
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
}