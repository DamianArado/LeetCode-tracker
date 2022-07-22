class Solution:
    def canShip(self, weights: List[int], days: int, maxCapacity: int) -> bool:
        currentDays, currentCapacity = 1, 0
        for weight in weights:
            # we can't even use a single ship with max capacity for this weight
            if weight > maxCapacity: return False
            # we need more days to ship
            if weight + currentCapacity > maxCapacity: 
                currentDays += 1
                # if we can't ship anymore
                if currentDays > days: return False
                currentCapacity = weight
            else:
                # keep adding more weight to my ship today
                currentCapacity += weight
        return True
    
    def shipWithinDays(self, weights: List[int], days: int) -> int:
        capacity, maxWeight, sumWeights = 0, 0, 0
        for weight in weights:
            maxWeight = max(maxWeight, weight);
            sumWeights += weight;
            
        # lets start our binary search
        start, end = maxWeight, sumWeights
        while start <= end:
            # mid is the max capacity that we are allocated for now in order to ship all the packages in days days
            mid = start + (end - start) // 2
            if self.canShip(weights, days, mid):
                # store the answer and try for better answer towards left
                capacity = mid;
                end = mid - 1;
            else:
                start = mid + 1;  # increase the days boss
        return capacity;