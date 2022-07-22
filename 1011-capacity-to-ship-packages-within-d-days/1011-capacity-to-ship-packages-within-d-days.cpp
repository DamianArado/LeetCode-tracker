class Solution {
    // hack! it's the same one as the min page allotment to student using BSearch
public:
    bool canShip(vector<int>& weights, int days, int maxCapacity) {
        int currentDays = 1, currentCapacity = 0;
        for(int weight : weights) {
            // we can't even use a single ship with max capacity for this weight
            if(weight > maxCapacity) return false;
            // we need more days to ship
            if(weight + currentCapacity > maxCapacity) {
                currentDays += 1;
                // if we can't ship anymore
                if(currentDays > days) return false;
                currentCapacity = weight;
            } else {
                // keep adding more weight to my ship today
                currentCapacity += weight;
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int capacity = 0, maxWeight = 0, sumWeights = 0;
        for(int weight : weights) {
            maxWeight = max(maxWeight, weight);
            sumWeights += weight;
        }
        // lets start our binary search
        int start = maxWeight, end = sumWeights;
        while(start <= end) {
            // mid is the max capacity that we are allocated for now in order to ship all the packages in days days
            int mid = start + (end - start) / 2;
            if(canShip(weights, days, mid)) {
                // store the answer and try for better answer towards left
                capacity = mid;
                end = mid - 1;
            } else start = mid + 1;  // increase the days boss
        }
        return capacity;
    }
};